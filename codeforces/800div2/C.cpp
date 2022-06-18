#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {	
	int n;
	cin >> n;

	i64 tot = 0;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		tot += a[i];
	}

	if (tot != 0) {
		cout << "No\n";
		return;
	}
	vector<i64> b(n);
	int k = n - 1;
	while (k >= 0 && a[k] == 0) k--;
	if (k == -1) {
		cout << "Yes\n";
		return;
	}
	for (int i = k; i > 0; i--) {
		if (a[i] >= b[i]) {
			cout << "No\n";
			return;
		} else {
			b[i - 1] += (b[i] - a[i]);
		}
	}
	cout << "Yes\n";
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}