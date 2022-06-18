	#include <bits/stdc++.h>
	using namespace std;
	using i64 = long long;


	void solve() {
		int n, k;
		cin >> n >> k;
		vector<int> a(n + 1);
		vector<i64> pref(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			pref[i] = pref[i - 1] + a[i];
		}

		if (k <= n) {

			i64 ans = 1ll * k * (k - 1) / 2;
			i64 tmp = 0;
			for (int i = k; i <= n; i++) {
				tmp = max(tmp, pref[i] - pref[i - k]);
			}
			cout << ans + tmp << endl;
			return ;
		} else {
			i64 ans = pref[n];
			ans += k - n;
			ans += 1ll * (n - 1) * (k - n);
			ans += 1ll * n * (n - 1) / 2;
			cout << ans << endl;
			return;
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