#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void query(int l, int r) {
	cout << "? " << l << " " << r << endl;
}
 
void solve() {
	int n;
	cin >> n;

	int l = 1, r = n;
	int ans = 1;
	while (l < r) {
		int mid = (l + r) >> 1;
		query(l, mid);
		int cnt = 0;
		for (int i = l; i <= mid; i++) {
			int val;
			cin >> val;
			if (val < l || val > mid) {
				cnt++;
			}
		}
		if (cnt % 2 != (mid - l + 1) % 2) {
			// 在里面..
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << "! " << l  << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}