#include<bits/stdc++.h>
using namespace std;
using i64 = long long;


// ok, 我完全搞懂了这种二类并查集的写法, 关键在于
// 了解其"敌人的敌人是朋友这一复杂的集合关系本身, 学一下jiangly的做法"
struct DSU {
	vector<int> f, g;
	DSU(int n): f(n), g(n) {
		iota(f.begin(), f.end(), 0);
	}
	// 这个返回值
	array<int, 2> leader(int x) {
		if (f[x] == x) {
			return {x, 0};
		}
		auto [y, z] = leader(f[x]);	
		f[x] = y;
		g[x] ^= z;
		return {f[x], g[x]};
	}

	bool merge(int a, int b, int z) {
		auto [x, u] = leader(a);
		auto [y, v] = leader(b);
		if (x == y) {
			return (u ^ v ^ z) == 0;
		}
		f[y] = x;
		g[y] = u ^ v ^ z;
 		return true;
	}
}; 

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	DSU dsu(n);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i][j] == a[j][i]) continue;

			if (dsu.merge(i, j, a[i][j] > a[j][i]) ^ (a[i][j] < a[j][i])) {
				swap(a[i][j], a[j][i]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " \n"[j == n - 1];
		}
	}
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