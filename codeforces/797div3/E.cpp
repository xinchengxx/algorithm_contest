#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> buck(k);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		buck[a[i] % k]++;
	}
	i64 ans = 0;
	for (int i = 1; i <= k / 2; i++) {
		int res = k - i;
		if (res != i) {
			ans += min(buck[i], buck[res]);
			if (buck[res] >= buck[i] && i != res - 1) {
				buck[res - 1] += (buck[res] - buck[i]);
			}
			buck[res] -= min(buck[res], buck[i]);
			if (i == res - 1) {
				//cout << buck[res] << endl;
				ans += buck[res] / 2;
			}
			//关键看怎么组合
		} else {
			ans += buck[i] / 2;
		}
	}
	///ans +=
	//cout << ans << endl;
	for (int i = 0; i < n; i++) {
		ans += (a[i] - a[i] % k) / k;
	}

	cout << ans << endl;
	// 关键在于多出来的可以凑出几个来;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}