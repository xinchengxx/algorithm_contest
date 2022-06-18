#include <iostream>
#include <vector>
#include <string.h>
#include <cstdio>
using namespace std;

int t, m, r;

int p1[201], p2[201]; // p, q数组;
int g[402][402];
bool vis[402];
bool f[201][201];
void dfs(int s, int cnt) {
	// 求dfs;
	vis[s] = true;
	if (s > m) {
		p2[cnt]++;
	} else {
		p1[cnt]++;
	}
	for (int i = 1; i <= 2 * m; i++) {
		if (!vis[i] && g[s][i]) {
			dfs(i, cnt);
		}
	}
}


void solve() {
	
	cin >> m >> r;
	memset(g, 0, sizeof(g));
	for (int i = 0; i < r; i++) {
		int a, b;
		cin >> a >> b;
		b += m;
		g[a][b] = 1;
	    g[b][a] = 1;
	}
	//cout << 1 << endl;
	memset(p1, 0, sizeof (p1));
	memset(p2, 0, sizeof (p2));
	memset(vis, 0, sizeof(vis));
	int cnt = 0;
	for (int i = 1; i <= 2 * m; i++) {
		if (!vis[i]) {
			dfs(i, cnt);
			cnt++;
		}
	}
	memset(f, 0, sizeof(f));
	f[0][0] = true;

	for (int k = 0; k < cnt; k++) {
		// 0 - 1 背包所以选择倒序遍历啊;
		for (int i = m / 2; i >= p1[k]; i--) {
			for (int j = m / 2; j >= p2[k]; j--) {
				if (f[i - p1[k]][j - p2[k]])
					f[i][j] = true;
			}
		}
	}

	for (int i = m / 2; i >= 0; i--) {
		if (f[i][i]) {
			printf("%d\n", i);
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}