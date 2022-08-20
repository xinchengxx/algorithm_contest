#include <bits/stdc++.h>
using namespace std;


void solve() {
	int n;
	cin >> n;

	int l = 0, r = 0, u = 0, d = 0;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		if (x < 0) {
			l = min(x, l);
		}
		if (x > 0) {
			r = max(x, r);
		}
		if (y < 0) {
			d = min(d, y);
		}
		if (y > 0) {
			u = max(u, y);
		}
	}
	cout << 2 * (r - l + u - d) << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	
	while (t--) {
		solve();
	}

	return 0;
}