#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


void solve() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << -1 << endl;
		return;
	} 
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> buck(n + 1);

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i] != j && buck[j] == 0) {
				cout << j << " ";
				buck[j] = 1;
				break;
			}
		}
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}
	return 0;
}