#include <bits/stdc++.h>
using namespace std;


void solve() {
	int n;
	cin >> n;
	vector<vector<int>> ans;
	int i;
	n--;
	for (i = 1; ; i++) {
		if (i * i > 2 * n) break;
	}	
	i--;	
	while (true) {
		ans.push_back({});
		int nxt = i * i - n;
		while (n >= nxt) {
			ans.back().push_back(n--);
		}
		if (n == -1 || n == 0) break;
		while (i * i > 2 * n) {
			i--;
		}
	}
	if (n == 0) {
		ans.push_back({0});
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
	}
	cout << "\n";
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