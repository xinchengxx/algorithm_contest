#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


//template<class T>
struct Fenwick {
	int n;
	vector<int> tree;
	Fenwick(int n) : tree(n + 1, INT_MIN / 2) {
		this->n = n;
	}
	// 只能维护1....k的区间最小值
	void clear() {
		//tree.resize(n + 1, INT_MIN);
		fill(tree.begin(), tree.end(), INT_MIN / 2);
	}
	int lowbit(int x) {
		return x & -x;
	}
	int ask(int v) {
		int ans = INT_MIN / 2;
		while (v) {
			ans = max(ans, tree[v]);
			v -= lowbit(v);
		}
		return ans;
	}
	void update(int v, int val) {
		while (v <= n) {
			tree[v] = max(tree[v], val);	
			v += lowbit(v);
		}
	}
};


void solve() {
	int n;
	cin >> n;

	vector<i64> pref(n + 1);
	vector<int> a(n + 1);
	vector<pair<i64, int>> pb;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
		pb.push_back({pref[i], -i});
	}
	sort(pb.begin(), pb.end());

	vector<int> order(n + 1);
	for (int i = 0; i < pb.size(); i++) {
		order[-pb[i].second] = i + 1;
	}

	Fenwick fen(n); // 1......n;
	//cout << fen.tree[1] << endl;
	//fen.update(2, 0);
	vector<int> dp(n + 1);
	//cout << 1 << endl;
	for (int i = 1; i <= n; i++) {
		// 有些时候下标从1开始会剩下很多力气;
		dp[i] = dp[i - 1] + (a[i] < 0 ? -1 : (a[i] > 0 ? 1 : 0));
		//cout << dp[i] << endl;
		//cout << fen.ask(order[i]) << endl;
 		dp[i] = max(dp[i], fen.ask(order[i]) + i);
		// fen.update(2)
		if (pref[i] > 0) {
			//cout << 1 << endl;
			dp[i] = i;
		}
		fen.update(order[i], dp[i] - i);
	}
	
	cout << dp[n] << "\n";
}



int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}