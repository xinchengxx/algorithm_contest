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
	bool flag = true;
	for (int i = 1; i < n; i++) {
		if (a[i] < a[0] || a[i] % a[0] ) {
			flag = false;
		}
	}
	if (flag) {
		cout << "Yes" << "\n";
	} else {
		cout << "No" << "\n";
	}
	// a[i] - a[i - 1] = 0;
	// 
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}