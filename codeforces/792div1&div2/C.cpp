#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> grid(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	int x = 0;
	while (x < n && is_sorted(grid[x].begin(), grid[x].end())) {
		x++;
	}

	if (x == n) {
		cout << "1 1" << endl;
		return ;
	}

	auto b = grid[x];
	sort(b.begin(), b.end());

	vector<int> p;
	for (int j = 0; j < m; j++) {
		if (grid[x][j] != b[j]) {
			p.push_back(j);
		}
	}

	if (p.size() > 2) {
		cout << -1 << endl;
		return;
	}

	for (int i = 0; i < n; i++) {
		swap(grid[i][p[0]], grid[i][p[1]]);
		if (!is_sorted(grid[i].begin(), grid[i].end())) {
			cout << -1 << endl;
			return;
		}
	}
	cout << p[0] + 1 << " " << p[1] + 1 << endl;
}



int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}