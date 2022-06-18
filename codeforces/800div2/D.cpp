#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {	
	int n;
	cin >> n;

	vector<int> p(n + 1, 0);
	vector<vector<int>> s(n + 1);
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		s[p[i]].push_back(i);
	}

	vector<i64> l(n + 1), r(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
	}		

	vector<i64> cnt(n + 1);
	i64 ans = 0;

	function<i64(int)> dfs = [&](int v) -> i64 {
		i64 tot = 0;
		if (s[v].size() == 0) {
			cnt[v] = 1;
			return r[v];
		}
		for (int i = 0; i < s[v].size(); i++) {
			tot += dfs(s[v][i]);
			cnt[v] += cnt[s[v][i]];
		}
		if (tot < l[v]) {
			cnt[v]++;
			return r[v];
		}
		return min(tot, r[v]);
	};
	dfs(1);
	cout << cnt[1] << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}