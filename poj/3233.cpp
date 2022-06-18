#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int n, k, mod;
 
// 矩阵快速幂模板

struct Matrix {
	int mtx[31][31];
	Matrix() {
		memset(mtx, 0, sizeof(mtx));
	}
	void build() {
		for (int i = 1; i <= n; i++)
			mtx[i][i] = 1;
	}
};

Matrix operator*(const Matrix& A, const Matrix& B) {
	Matrix C;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int tot = 0;
			for (int k = 1; k <= n; k++) {
				tot = (tot + A.mtx[i][k] * B.mtx[k][j] % mod) % mod;
			} 
			C.mtx[i][j] = tot;
		}
	return C;
}

Matrix& operator+(Matrix& A, const Matrix& B) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			A.mtx[i][j] = (A.mtx[i][j] + B.mtx[i][j]) % mod;
		}
	return A;
}

Matrix ans, arr;

Matrix quick_power(int k) {
	Matrix ret;
	Matrix a = arr;
	ret.build();
	while (k) {
		if (k & 1) {
			ret = ret * a;
		}
		a = a * a;
		k >>= 1;
	}
	return ret;
} 

inline int read() {
	int tot = 0;
	bool f = false;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		tot = tot * 10 + ch - '0';
		ch = getchar();
	}
	return f == true ? -tot : tot;
}

// 近似为f(k) = f (k / 2) + n^3 * logk //此处n是常数

// n^3 * logk 时间复杂度 
Matrix Solve(int n) {
	Matrix ret;
	if (n == 1) {
		ret = arr;
		return ret;
	}
	if (n % 2 == 1) {
		ret = ret + quick_power(n);
		ret = ret + Solve(n - 1);
		return ret;
	} else {
		Matrix tmp = quick_power(n / 2);
		ret = Solve(n / 2);
		Matrix ret2;
		ret2 = ret * tmp;
		ret = ret + ret2;
		return ret;
	}
} 


int main() {
	n = read(), k = read(), mod = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
				arr.mtx[i][j] = read();
	ans = Solve(k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%d ", ans.mtx[i][j]);
		cout << endl;
	}
	return 0;
}
