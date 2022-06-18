#include <bits/stdc++.h>
using namespace std;

int t;

// 首先要大胆猜测


void solve() {
	int n;
	cin >> n;
	bool one = false;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		arr[i] = val;
		if (val == 1) one = true;
	}
	if (!count(arr.begin(), arr.end(), 1)) {
		cout << "YES\n";
		return;
	}
	sort(arr.begin(), arr.end());
	for (int i = 1; i < n; i++) {
		if (arr[i] - arr[i - 1] == 1) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);

	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}