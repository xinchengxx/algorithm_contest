#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	vector<int> pref(n + 1);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'B') {
			pref[i + 1] = pref[i] + 1;
		} else {
			pref[i + 1] = pref[i];
		}
	}
	//0... k - 1
	// pref[k] - pref[0]
	int ans = INT_MAX;
	for (int i = k; i <= n; i++) {
		ans = min(ans, k - (pref[i] - pref[i - k]));
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