#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int t;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> d = a;
	sort(d.begin(), d.end());

	//从后往后维护;
	// 3 1 5 3 
	// 1 3 3 5
	// 2 1
	for (int i = n - 1; i >= 1; i -= 2) {
		if (a[i] == d[i] && a[i - 1] == d[i - 1]) {
			continue;
		}
		if (a[i] == d[i - 1] && a[i - 1] == d[i]) {
			continue;
		}
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
}


int main() {
	cin >> t;
	while (t--) {
		solve();
		
	}

	return 0;
}