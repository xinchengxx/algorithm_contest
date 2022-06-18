#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


void solve() {
	int n;
	cin >> n;

	bool ok = false;
	vector<int> a(n);
	int cnt = 0;
	int mi = INT_MAX, minum = INT_MAX;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 1) {
			ok = true;
		} else {
			cnt++;
			int micnt = 0;
			int tmp = a[i];
			while (tmp % 2 == 0) {
				tmp /= 2;
				micnt++;
			}
			if (micnt < mi) {
				mi = micnt;
			}
		}
	}
	if (ok) {
		cout << cnt << endl;
	} else {
		cout << cnt - 1 + mi << endl;
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