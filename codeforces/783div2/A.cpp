#include <bits/stdc++.h>
using namespace std;

int t;
void solve() {
	int m, n;
	cin >> n >> m; // n, m
	if (n <= m) swap(n, m);
	if (m == 1 && n >= 3) {
		cout << -1 << endl;
		return;
	}
	int res = n - m;
	int ans = 0;
	if (res % 2 == 0) {
		// 比如多偶数步;
		ans = 2 * (n - 1);
	} else {
		ans = (n - 1) + (n - 2);
	}
	cout << ans << endl;
}
int main () {
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}