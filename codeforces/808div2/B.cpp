#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, l, r;
	cin >> n >> l >> r;
	vector<int> ans(n + 1);
	for (int i = 1; i <= n; i++) {
		int num = r / i * i;
		if (num < l) {
			cout << "No" << endl;
			return;
		}
		ans[i] = num;
	}
	cout << "Yes" << endl;
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " \n"[i == n];
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