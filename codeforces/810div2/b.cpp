#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// 要么删要么不善..
	int cnt = 0;
	vector<vector<int>> g(n);
	int ans = INT_MAX; //如果总边数是奇数... 如何让最后变成偶数... 这是一个套路
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		cnt++;
		g[x].push_back(y);
		g[y].push_back(x);
		ans = min(ans, a[x] + a[y]);
	}
	if (cnt % 2 == 0) {
		cout << 0 << endl;
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (g[i].size() % 2 == 1) {
			ans = min(ans, a[i]);
		}
	}	
	cout << ans << endl;
	// 关键在于有没有奇数的边...
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}