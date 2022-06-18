#include <bits/stdc++.h>
using namespace std;
using i64 = long long;



int main() {
	int n, m, q;
	cin >> n >> m >> q;

	// 太厉害了这个写法, 因为总是增加或者删减1 (也即我们需要维护的是前缀里面有多少个1)
	// 不过是把二维映射成了一维

	int o = 0, cnt = 0;
	vector<int> a(n * m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == '*') {
				if (a[cnt]) {
					o++;
				}
				cnt++;
				a[j * n + i] = 1;
				if (j * n + i < cnt) {
					o++;
				}
			}
		}
	}	

	while (q--) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		int i = y * n + x;

		if (!a[i]) {
			if (a[cnt]) {
				o++;
			}
			cnt++;
			a[i] = 1;
			if (i < cnt) {
				o++;
			}
		} else {
			if (i < cnt) {
				o--;
			}
			a[i] = 0;
			cnt--;
			if (a[cnt]) {
				o--;
			}
		}
		cout << cnt - o << "\n";
	}

	return 0;
}