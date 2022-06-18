#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	int mx = INT_MIN;
	int l1 = -1, l2 = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j]; 
			if (grid[i][j] > mx) {
				l1 = i,
				l2 = j;
				mx = grid[i][j];
			}
		}
	}
	int ans = max(l1 + 1, n - l1) * max(l2 + 1, m - l2);
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