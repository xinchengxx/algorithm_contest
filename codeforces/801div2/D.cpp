#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

// jiangly对此题的解法


void solve() {
	int n;
	cin >> n;

	vector<vector<int>> tree(n);
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	if (n == 1) {
		cout << "0\n";
		return;
	}

	if (all_of(tree.begin(), tree.end(), [&](auto a) {
		return a.size() <= 2;
	})) {
		cout << "1\n";
		return;
	}

	int ans = 0;
	vector<bool> vis(n);
	
	for (int i = 0; i < n; i++) {
		if (tree[i].size() == 1) {
			//叶子节点
			ans++;
			int j = tree[i][0], k = i;
			while (tree[j].size() <= 2) {
				k ^= tree[j][0] ^ tree[j][1]; // 链子往上的过程
				swap(j, k); //
			}
			if (!vis[j]) {
				vis[j] = true;
				ans--;
			}
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