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
	for (int i = 0; i < n; i++) {
		int x = 0;
		for (int j = 0; j < n; j++) {
			if (j == i) {
				continue;
			} 
			x ^= a[j];
		}
		
		if (x == a[i]) {
			cout << a[i] << endl;
			return;
		}
	}
	int ans = 0;

}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}