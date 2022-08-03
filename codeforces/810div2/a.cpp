#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


void solve() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		cout << i % n + 1 << " \n"[i == n];
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