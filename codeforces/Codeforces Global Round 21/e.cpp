#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;
using i64 = long long;
// assume -P <= x < 2P
// norm 规格化
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    Z(i64 x) : x(norm(x % P)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        // 由于费马小定理, 把除号转化为*
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        i64 v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
};
 
int main() {
   	ios::sync_with_stdio(false);
   	cin.tie(nullptr);
    
   	int n;
   	cin >> n;

   	vector<int> a(n + 1);
   	for (int i = 0; i <= n; i++) {
   		cin >> a[i];
   	}

   	// 此处的z可以当作不会超过mod的一切正整数来用了，包括* / 运算;
   	int N = a[0] + n;
   	vector<Z> fac(N + 1), invfac(N + 1);
   	fac[0] = 1;
   	for (int i = 1; i <= N; i++) {
   		fac[i] = fac[i - 1] * i;
   	}

   	invfac[N] = fac[N].inv();
   	for (int i = N; i > 0; i--) {
   		invfac[i - 1] = invfac[i] * i;
   	}
   	Z ans;
   	for (int i = 0; i <= n; i++) {
   		if (a[i] > 0) {
   			ans += fac[i + a[i]] * invfac[i + 1] * invfac[a[i] - 1];
   		}
   	}
    
    cout << ans << endl;
    return 0;
}