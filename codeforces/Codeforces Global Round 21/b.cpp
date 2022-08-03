#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	bool nice = true;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i]) {
			nice = false;
		}
	}
	if (nice) {
		cout << 0 << endl;
		return;
	}
	int l = 0, r = n - 1;
	while (l < n && a[l] == 0) l++;
	while (r >= 0 && a[r] == 0) r--;
	for (int i = l; i <= r; i++) {
		if (a[i] == 0) {
			cout << 2 << endl;
			return;
		}
	}
	cout << 1 << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}