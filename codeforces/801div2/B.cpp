#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n % 2 == 1) {
		cout << "Mike" << endl;
		return ; 
	} 
	// 37 100
	int t1 = INT_MAX, t2 = INT_MAX;
	int pos1 = -1, pos2 = -1;
	for (int i = 0; i < n; i += 2) {
		if (a[i] < t1) {
			pos1 = i;
			t1 = a[i];
		}
	}
	for (int i = 1; i < n; i += 2) {
		if (a[i] < t2) {
			pos2 = i;
			t2 = a[i];
		}
	}
	if (t1 > t2) {
		cout << "Mike" << endl;
	} else if (t1 < t2) {
		cout << "Joe" << endl;
	} else {
		if (pos1 < pos2) {
			cout << "Joe" << endl;
		} else {
			cout << "Mike" << endl;
		}
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