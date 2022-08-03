#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n;
	cin >> n;
	bool five = false, ten = false, other =false;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 10 == 0) {
			ten = true;
		} else if (a[i] % 10 == 5) {
			five = true;
		} else {
			other = true;
		}
	}
	if (other && (five || ten)) {
		cout << "No" << endl;
		return;
	}
	if (!other) {
		if (five && !ten) {
			for (int i = 1; i < n; i++) {
				if (a[i] != a[0]) {
					cout << "No" << endl;
					return;
				}
			}
			cout << "Yes" << endl;
			return;
		} else {
			for (int i = 0; i < n; i++) {
				if (a[i] % 10 == 5) {
					a[i] += 5;
				}
			}
			for (int i = 1; i < n; i++) {
				if (a[i] != a[0]) {
					cout << "No" << endl;
					return;
				}
			}
			cout << "Yes" << endl;
			return;
		}
	} 
	// 以2;
	for (int i = 0; i < n; i++) {
		while (a[i] % 10 != 2) {
			a[i] += a[i] % 10;
		}
	}
	for (int i = 1; i < n; i++) {
		if ((a[i] - a[0]) % 20 != 0) {
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
	// a[i] % 
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}