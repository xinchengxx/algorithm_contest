#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
  	int n;
  	cin >> n;
  	vector<vector<array<int, 3>>> adj(n);
  	for (int i = 1; i < n; i++) {
  		int x, a, b;
  		cin >> x >> a >> b;
  		x--;
  		adj[x].push_back({i, a, b});
  		// 自动解引用可以对pair, array生效
  	}

  	vector<int> ans(n);
  	vector<i64> A(n), B(n), s;
  	function<void(int)> dfs = [&](int u) {
  		s.push_back(B[u]);
  		if (u != 0) {
  			// >关键在于 upper_bound <=
  			// upper_bound
  			ans[u] = upper_bound(s.begin(), s.end(), A[u]) - s.begin() - 1;
  		}
  		for (auto [v, a, b]: adj[u]) {
  			A[v] = A[u] + a;
  			B[v] = B[u] + b;
  			dfs(v);
  		}
  		s.pop_back();
  	};
  	dfs(0);
  	for (int i = 1; i < n; i++) {
  		cout << ans[i] << " \n"[i == n - 1];
  	}
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}