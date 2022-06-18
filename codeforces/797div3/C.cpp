#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> s(n), f(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> f[i];
	}
	int final = 0;
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		if (s[i] >= final) {
			d[i] = f[i] - s[i];
			final = f[i];
		} else {
			d[i] = f[i] - final;
			final = f[i];
		}
	}
	for (int i = 0; i < n; i++) {
		cout << d[i] << " \n"[i == n - 1];
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