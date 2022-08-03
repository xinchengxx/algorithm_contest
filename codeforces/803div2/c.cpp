#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	bool nice = true;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] != 0) {
			cnt++;
			if (cnt >= 2) {
				nice = false;
			}
		}
	}
	sort(a.begin(), a.end());
	if (nice == true) {
		cout << "Yes" << endl;
		return;
	}
	if (n >= 5) {
		if (a[0] + a[n - 1] != 0) {
			cout << "No" << endl;
			return;
		}
		for (int i = 1; i < n - 1; i++) {
			if (a[i] != 0) {
				cout << "No" << endl;
				return;
			}
		}
		cout << "Yes" << endl;
		return;
	} else if (n == 3) {
		for (int i = 0; i < 3; i++) {
			if (a[i] == (a[0] + a[1] + a[2])) {
				cout << "Yes" << endl;
				return;
 			}
		}
		cout << "No" << endl;
	} else if (n == 4) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					bool flag = false;
					for (int t = 0; t < n; t++) {
						
						if (a[i] + a[j] + a[k] == a[t]) {
							flag = true;
						}
					
					}
					if (!flag) {
						cout << "No" << endl;
						return;
					}
				}
			}
		}
		cout << "Yes" << endl;
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