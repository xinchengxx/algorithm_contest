#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (k == 1) {
		cout << (n - 1) / 2 << endl;
		return;
	}

	int ans = 0;
	for (int i = 1; i < n - 1; i ++) {
		if (a[i] > a[i - 1] + a[i + 1]) {
			ans++;
		}
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}