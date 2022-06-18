#include <bits/stdc++.h>
using namespace std;

//使用floyd一般搭配使用邻接矩阵哦
int a[101][101];

int main() {
	int n, m;
	cin >> n >> m;

	memset(a, 0, sizeof(a));

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;

		a[from][to] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int j = 1; j <= n; j++) {
			for (int i = 1; i <= n; i++) {
				if (a[i][k] && a[k][i]) {
					a[i][j] = 1;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (a[i][j] || a[j][i]) {
				cnt++;
			}
		}
		if (cnt == n - 1) ans++;
 	}
 	cout << ans << endl;
 	return 0;
}