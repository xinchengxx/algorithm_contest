#include <bits/stdc++.h>
using namespace std;
using i64 = long long; // 


void solve() {
	int n;
	cin >> n;

	int t1 = 0, t2 = 0;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num % 2 == 1) {
			t1++;  
		} else {
			t2++;
		}
	}
	cout << min(t1, t2) << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}