#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n;
	cin >> n;
	if (n % 3 == 0) {
		cout << n / 3 << " " << n / 3 + 1 << " " << n / 3 - 1 << endl;
		return;
	} else if (n % 3 == 1) {
		cout << (n - 4) / 3 + 1 << " " << (n - 4) / 3 + 3 << " " << (n - 4) / 3 << endl;
		return;
	} else {
		cout << (n - 5) / 3 + 2 << " " << (n - 5) / 3 + 3 << " " << (n - 5) / 3 << endl;
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