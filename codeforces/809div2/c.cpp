#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n;
	cin >> n;

	vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}	
	i64 ans = 0;
	if (n % 2 == 1) {
		for (int i = 1; i < n; i += 2) {
			if (a[i] <= max(a[i - 1], a[i + 1])) {
				ans += max(a[i - 1], a[i + 1]) - a[i] + 1;
			}
		}
	} else {
		// 需要统计后面的;
		vector<i64> pref_odd(n), pref_even(n);
		// 注意现在n 是个 偶数
		// 统计奇数的;
		pref_odd[1] = max(0ll, max(a[0], a[2]) - a[1] + 1);
		for (int i = 3; i < n - 1; i += 2) {
			if (a[i] <= max(a[i - 1], a[i + 1])) {
				pref_odd[i] = pref_odd[i - 2] + (max(a[i - 1], a[i + 1]) - a[i] + 1); 
			} else {
				pref_odd[i] = pref_odd[i - 2];
			}
		}
		pref_even[n - 2] = max(0ll, max(a[n - 3], a[n - 1]) - a[n - 2] + 1);
		for (int i = n - 4; i >= 2; i -= 2) {
			if (a[i] <= max(a[i - 1], a[i + 1])) {
				pref_even[i] = pref_even[i + 2] + (max(a[i - 1], a[i + 1]) - a[i] + 1); 
			} else {
				pref_even[i] = pref_even[i + 2];
			}
		}
		ans = min(pref_even[2], pref_odd[n - 3]);
		//ans = min(pref_even[2], pref[];
	
		//cout << ans << " " << endl;
		for (int i = 3; i < n - 1; i += 2) {
			ans = min(ans, pref_odd[i - 2] + pref_even[i + 1]);
		}
		// 表示从这个开始切换到后半部分
		// 0 1 2 3 
		// 0 1 2 3 4 5
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