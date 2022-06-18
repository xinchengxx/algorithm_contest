#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	// x | y >= x
	int x;
	cin >> x;
	int y = 0;
	for (int i = 0; i < 32; i++) {
		if ((1 << i) & x) {
			y |= (1 << i);
			break;
		}
	}
	if (__builtin_popcount(x) == 1) {
		for (int j = 0; j < 32; j++) {
			if (!((1 << j) & x)) {
				y |= (1 << j);
				break;
			}
		}
	}
	cout << y << endl;
}


int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}