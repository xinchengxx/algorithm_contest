#include <iostream>
#include <vector>
using namespace std;

int m, n, ans;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<vector<int>> cnt;


// why this,	

void dfs(vector<vector<int>>& cnt, vector<vector<int>>& f, int x, int y) {
	if (cnt[x][y]) {
		return ;
	}
	cnt[x][y] = 1;
	for (int k = 0; k < 4; k++) {
		int dx = x + dir[k][0];
		int dy = y + dir[k][1];
		if (dx >= 0 && dx < m && dy >= 0 && dy < n && f[dx][dy] < f[x][y]) {
			dfs(cnt, f, dx, dy);
			cnt[x][y] = max(cnt[x][y], cnt[dx][dy] + 1);
		}
	}

	ans = max(ans, cnt[x][y]);
}

int main() {
	cin >> m >> n;
	cnt.resize(m, vector<int>(n));
	vector<vector<int>> f(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> f[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!cnt[i][j]) {
				dfs(cnt, f, i, j);
			}
		}
	}
	cout << ans << "\n";
	return 0;	
}