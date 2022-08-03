#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// 学习一下jiangly的写法... 这个神秘的数学等式...
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<i64> p(n);
	for (int i = 1; i < n; i++) {
		p[i] = p[i - 1] + max(0, a[i - 1] - a[i]);
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		if (x < y) {
			cout << p[y] - p[x] << endl;
		} else {
			cout << a[x] - a[y] + p[x] - p[y] << endl;
		}
	}
	return 0;
}