#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	int tot = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		tot += a[i] - 1;
	}

	if (tot % 2 == 1) {
		cout << "errorgorn" << endl;
	} else {
		cout << "maomao90" << endl;
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

