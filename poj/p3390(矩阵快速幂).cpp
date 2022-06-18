#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int mod = 1e9 + 7;

// 注意由于矩阵乘法满足结合律, 因此可以采用采用快速幂的方式....
int n, k;



inline ll read() {
	ll tot = 0;
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

struct Matrix {
	ll mtx[101][101];
	void build() {
		for (int i = 1; i <= n; i++)
			mtx[i][i] = 1;
	}
};

Matrix ans, arr;

Matrix operator* (const Matrix& a, const Matrix& b) {
	Matrix z;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				z.mtx[i][j] = (z.mtx[i][j] + a.mtx[i][k] * b.mtx[k][j] % mod) % mod;
			}
		}
	return z;
	}
}



void quick_power(int k) {
	// 如果我不想改变原来的数组的话...
	ans.build();
	while (k) {
		if (k & 1) {
			ans = ans * arr;
		}
		arr = arr * arr;
		k >>= 1;
	}
}



int main() {
	n = read(), k = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
				arr.mtx[i][j] = read();
   
	quick_power(k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << ans.mtx[i][j] << " ";
		cout << endl;
	}
	return 0;
}