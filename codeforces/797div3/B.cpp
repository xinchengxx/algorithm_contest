#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	int last = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] < b[i]) {
			cout << "No\n";
			return;
		} else if (b[i] != 0) {
			if (last == -1) {
				last = a[i] - b[i];
			} else if (last != a[i] - b[i]) {
				cout << "No\n";
				return;
			}
		}
	}
	if (last == -1)
	cout << "Yes" << endl;
	else {
		
		for (int i = 0; i < n; i++) {
			if (b[i] == 0) {
				if (a[i] > last) {
					cout << "No\n";
					return;
				}
			}
		}
		cout << "Yes\n";
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