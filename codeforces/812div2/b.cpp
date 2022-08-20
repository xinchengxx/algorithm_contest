#include <bits/stdc++.h>
using namespace std;


void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int mx = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (mx == -1 || a[i] > a[mx]) {
			mx = i;
		}
	}
	//cout << mx << endl;
	bool nice = true;
	for (int i = mx; i >= 1; i--) {
		if (a[i] < a[i - 1]) {
			nice = false;
		}
	}
	for (int i = mx; i < n - 1; i++) {
		if (a[i] < a[i + 1]) {
			nice = false;
		}
	}
	if (nice) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	
	while (t--) {
		solve();
	}

	return 0;
}