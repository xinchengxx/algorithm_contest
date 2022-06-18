#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, x;
	cin >> n >> x;	

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	i64 ans = 0;
	for (int i = 1; i < n; i++) {
		ans += abs(a[i] - a[i - 1]);
	}

	int mx = *max_element(a.begin(), a.end());
	int mi = *min_element(a.begin(), a.end());		
	if (mx < x) {
		ans += min(mx + 1 - max(a[0], a[n - 1]) + (x - (mx + 1)), 2 * (x - mx));
	}
	ans += min(min(a[0], a[n - 1]) - (mi - 1) + mi - 2, 2 * (mi - 1));
	cout << ans << "\n";
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}	
	return 0;
}