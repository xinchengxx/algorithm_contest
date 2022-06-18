#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	int eq = 0;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i - 1] == a[i]) eq++;
	}
	if (eq == 0 || eq == 1) {
		cout << 0 << endl;
		return;
	} 

	int l = 1;
	// 找到第一段连续的;
	while (a[l] != a[l + 1]) l++; 
	int r = n;
	while (a[r - 1] != a[r]) r--;
	//cout << l << " " << r << endl;
	int ans = r - l - 2;
	if (ans == 0) ans++;
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

