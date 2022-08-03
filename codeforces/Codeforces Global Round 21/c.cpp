#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int k;
	cin >> k;
	vector<int> b(k);
	for (int i = 0; i < k; i++) {
		cin >> b[i];
	}

	// 看看这个lambda表达式里面的auto
	// 还有就是vector重载了==号
	auto get = [&](auto a) {
		int n = a.size();
		vector<array<i64, 2>> b;
		for (int i = 0; i < n; i++) {
			i64 x = a[i], c = 1;
			while (x % m == 0) {
				x /= m;
				c *= m;
			}
			if (!b.empty() && x == b.back()[0]) {
				b.back()[1] += c;
			} else {
				b.push_back({x, c});
			}
		}
		return b;
	};

	if (get(a) == get(b)) {
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