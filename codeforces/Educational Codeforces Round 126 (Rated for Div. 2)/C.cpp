#include <bits/stdc++.h>
using namespace std;
int t;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	// tar2 = a[n - 1] + 1;
	int tar1 = a[n - 1], tar2 = a[n - 1] + 1;
	vector<int> arr1, arr2;
	for (int i = 0; i < n ; i++) {
		if (tar1 > a[i]) {
			arr1.push_back(tar1 - a[i]);
		} 
		if (tar2 > a[i]) {
			arr2.push_back(tar2 - a[i]);
		}
	}
	if (arr1.size() == 0) {
		cout << 0 << endl;
		return ;
	}
	int ans = 1;
	// 偶数日
	int l = 1, r = 3e9;
	while (l <= r) {
		int mid = (l + r) >> 1;
		int two, one;
		if (mid % 2 == 0) {
			two = mid / 2;
			one = mid / 2;
		} else {
			two = mid / 2;
			one = (mid + 1) / 2;
		}
		int i;
		int cur2 = two, cur1 = one;
		for (i = 0; i < arr1.size(); i++) {
			if (cur2 * 2 + cur1 < arr1[i])
				break;
			int mx = arr1[i] / 2;
			int sub = min(mx, cur2);
			cur2 -= min(mx, cur2);
			int left = arr1[i] - sub * 2;
			if (cur1 < left) break;
			cur1 -= left;
		}
		int j;
		cur2 = two, cur1 = one;
		for (j = 0; j < arr2.size(); j++) {
			if (cur2 * 2 + cur1 < arr2[j])
				break;
			int mx = arr2[j] / 2;
			int sub = min(mx, cur2);
			cur2 -= min(mx, cur2);
			int left = arr2[j] - sub * 2;
			if (cur1 < left) break;
			cur1 -= left;
		}
		if (i == arr1.size() || j == arr2.size()) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans << endl;
}


int main() {
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}