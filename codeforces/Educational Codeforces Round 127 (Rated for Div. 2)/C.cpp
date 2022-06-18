#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, x;
	cin >> n >> x;

	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());
	vector<i64> pref(n + 1);
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + a[i];
	}

	i64 ans = 0; 
	int day = 0;
	int mx = n;
	// 最多nlogn
	while (1) {
		int l = 1, r = mx;
		int res = 0; 
		// 1...mid
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (pref[mid] + 1ll * day * mid > x) {
				r = mid - 1;
			} else {
				res = mid;
				l = mid + 1;
			}
		}
		// 稍微优化一下;
		if (res == 0) {
			break;
		}
		int rest = x - (pref[res] + 1ll * day * res);
		//cout << day << " " << rest << " " << res << endl;
		int nx = rest / res;
		ans += 1ll * (nx + 1) * res;
		day += nx + 1;
		mx = res - 1;
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