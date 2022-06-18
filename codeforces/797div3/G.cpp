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


	map<int, int> s;
	auto add = [&](int i, int x) {
		s[i] = x;

		auto it = s.find(i); // .find()返回迭代器, .count
		if (it != s.begin() && x >= prev(it)->second) {
			s.erase(it);
			return;
		}

		while (next(it) != s.end() && x <= next(it)->second) {
			s.erase(next(it));
		}
	};

	for (int i = 0; i < n; i++) {
		add(i, a[i]);
	}
	for (int i = 0; i < m; i++) {
		int k, d;
		cin >> k >> d;
		k--;
		a[k] -= d;
		add(k, a[k]);
		cout << s.size() << " \n"[i == m - 1];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}