#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	if ((n + 1) / 2 < k) {
		cout << "-1\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0 || i > (2 * k - 1)) {
			for (int j = 1; j <= n; j++) {
				cout << "." ;
			}
			cout << "\n";
		} else {
			for (int j = 1; j <= n; j++) {
				if (j == i) {
					cout << "R";
				} else {
					cout << ".";
				}
			}
			cout << "\n";
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
	return 0;
}