#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n;
	cin >> n;

	vector<vector<int>> tree(n);
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	if (n == 1) {
		cout << "0\n";
		return; 
	}

	// 这个思路看懂了.... 关键是要学会画图分析....
	function<int(int, int)> dfs = [&](int u, int fa) {
		int sum = 0, z = 0;
		for (int v: tree[u]) {
			if (v == fa) continue;
			int x = dfs(v, u);
			sum += x;
			if (x == 0) {
				z++;
			}
		}
		return sum + max(0, z - 1);
	};
	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (tree[i].size() > 2)
		ans = min(ans, dfs(i, -1));
		else {

			// 想清楚
			ans = min(ans, dfs(i, - 1) + 1);
		}
	}
	cout << ans << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}