#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int t;

void solve() {
	int n, B, x, y;
	cin >> n >> B >> x >> y;

	i64 tot = 0;

	// ai <= B
	// ai = ai - 1 + x
	// ai = ai - 1 - y;
	i64 last = 0;
	for (int i = 1; i <= n; i++) {
		if (last + x <= B) {
			last = last + x;
			tot += last;
		} else {
			last = last - y;
			tot += last;
		}
	}
	cout << tot << "\n";

}


int main() {
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}