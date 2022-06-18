#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;

	long long ans = 0;

	ans = 1ll * a * n / b + 1;

	// 
	cout << ans << endl;
}


int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}