#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	string a, b;
	cin >> a >> b;
	string c;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (k == 1) {
		int i = 0, j = 0;
		int last = 0;
		if (a[0] < b[0]) {
			last = 0;
		} else {
			last = 1;
		}
		while (i < a.size() && j < b.size()) {
			if (last == 0) {
				c += a[i];
				i++;
				last = 1;
			} else {
				c += b[j];
				j++;
				last = 0;
			}
		}
		cout << c << endl;
		return;
	}


	int i = 0, j = 0;
	int cnt = 0, last = -1;
	while (i < a.size() && j < b.size()) {
		if (a[i] < b[j]) {
			if (last == -1 || last == 0) {
				cnt++;
				last = 0;
			} else {
				cnt = 1;
				last = 0;
			}
			c += a[i];
			i++;
			if (i == a.size()) break;
			if (cnt == k) {
				c += b[j];
				j++;
				last = 1;
				cnt = 1;
			}
		} else {
			if (last == -1 || last == 1) {
				cnt++;
				last = 1;
			} else {
				cnt = 1;
				last = 1;
			}
			c += b[j];
			j++;
			if (j == b.size()) break;
			if (cnt == k) {
				last = 0;
				cnt = 1;
				c += a[i];
				i++;
			}
		}
	}

	cout << c << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}
	return 0;
}