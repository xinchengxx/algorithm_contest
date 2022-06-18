#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n;
	cin >> n;
	// sum(red) > sum(blue)
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	int bc = 0, rc = 0, l = 0, r = n - 1;
	i64 rs = 0, bs = 0;
	// 维护一个双指针;
	while (l <= r) {
		while (l <= r && rs <= bs) {
			rs += a[r];
			rc++;
			r--;
		}
		if (bc > rc && rs > bs) {
			cout << "yes\n";
			return;
		}
		while (l <= r && bc <= rc) {
			bc += 1;
			bs += a[l];
			l++;
		}
		if (bc > rc && rs > bs) {
			cout << "yes\n";
			return;
		}
	}
	cout << "No\n";
}



int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}