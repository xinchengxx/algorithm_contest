#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	string ans(m, 'B');

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		a--;
		// 0.. m - 1 - a;
		if (ans[min(m - 1 - a, a)] == 'B') {
			ans[min(m - 1 - a, a)] = 'A';
		} else {
			ans[max(m - 1 - a, a)] = 'A';
		}
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}