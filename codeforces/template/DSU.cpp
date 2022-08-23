#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct DSU {
	vector<int> f, siz;
	DSU(int n) : f(n), siz(n, 1) {
		iota(f.begin(), f.end(), 0);
	}
	int leader(int x) {
		if (x == f[x]) {
			return x;
		}
		return f[x] = leader(f[x]);
	}
	bool same(int x, int y) {
		return leader(x) == leader(y);
	}
	bool merge(int x, int y) {
		x = leader(x);
		y = leader(y);
		if (x == y) return false;
		siz[x] += siz[y];
		f[y] = x;
		return true;
	}
	int size(int x) {
		return siz[leader(x)];
	}
};
