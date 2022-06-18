#include <bits/stdc++.h>
using namespace std;

int t;

// 我超, 这题关于对于mod的性质用到了一定程度
// 可能对我来说需要考虑一下使用一下纸笔
// n == k * (k + 1) / 2 mod k;
// n >= k * (k + 1) / 2 就可以了

// 那么它是如何构造的...

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		long long x = n;
		while (x % 2 == 0) x /= 2;
		if (x == 1) {
			cout << "-1\n";
			continue;
		} 
		if (x <= 2e9 + 1 && x * (x + 1) / 2 <= n) {
			cout << x << "\n";
		} else {
			cout << 2 * (n / x) << "\n";
		}
	}
	return 0;
}