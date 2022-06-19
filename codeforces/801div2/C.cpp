#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	if ((n + m - 1) % 2 != 0) {
		cout << "No\n";
		return;
	}
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2)));
	if (a[0][0] == 1) {
		dp[0][0][0] = 1;
		dp[0][0][1] = 1;
	}
	for (int i = 1; i < m; i++) {
		if (a[0][i] == 1) {
			dp[0][i][0] = dp[0][i - 1][0] + 1;
			dp[0][i][1] = dp[0][i - 1][1] + 1;			
		} else {
			dp[0][i][0] = dp[0][i - 1][0];
			dp[0][i][1] = dp[0][i - 1][1];
		}
	}
	for (int i = 1; i < n; i++) {
		if (a[i][0] == 1) {
			dp[i][0][0] = dp[i - 1][0][0] + 1;
			dp[i][0][1] = dp[i - 1][0][1] + 1;	
		} else {
			dp[i][0][0] = dp[i - 1][0][0];
			dp[i][0][1] = dp[i - 1][0][1];	
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (a[i][j] == 1) {
				dp[i][j][0] = min(dp[i - 1][j][0], dp[i][j - 1][0]) + 1;
				dp[i][j][1] = max(dp[i - 1][j][1], dp[i][j - 1][1]) + 1;
			} else {
				dp[i][j][0] = min(dp[i - 1][j][0], dp[i][j - 1][0]);
				dp[i][j][1] = max(dp[i - 1][j][1], dp[i][j - 1][1]);
			}
		}
	}
	if (dp[n - 1][m - 1][0] <= (n + m - 1) / 2 && dp[n - 1][m - 1][1] >= (n + m - 1) / 2) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
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