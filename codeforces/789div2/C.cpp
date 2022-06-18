#include <bits/stdc++.h>
using namespace std;
using i64 = long long;



// 这个题的做法真是太妙了, 经典的维护中间的变量，有一种很神奇的思想在里面，分批次来

void solve() {
	int n;
	cin >> n;

	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}

	i64 ans = 0;
	vector<int> cnt(n);
	for (int b = 0; b < n; b++) {
		int d = 0;
		for (int c = n - 1; c > b; c--) {
			ans += cnt[c] * d;
			d += p[c] < p[b];// pb > pd
			cnt[c] += p[b] < p[c];     //pc > pa
		}
	}

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