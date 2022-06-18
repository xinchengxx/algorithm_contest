#include <bits/stdc++.h>
using namespace std;

int t;
void solve() {
	int n;
	map<int, int> m;
	cin >> n;
	int time = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		m[val]++;
		if (m[val] > time) {
			time = m[val];
		}
	}
	int tot = time;
	while (tot < n) {
		ans++;
		if (tot * 2 >= n) {
			ans += n - tot;
			tot = n;
			break;
		}
		ans += tot;
		tot *= 2;
	}
	cout << ans << endl;
}

int main() {
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}