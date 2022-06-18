#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int cnt(vector<int> &schedule, int d, int n){
    int mx = 0, mn = INT_MAX;
    for(int i = 1; i < n; ++i){
        mx = max(mx, schedule[i] - schedule[i - 1] - 1);
        mn = min(mn, schedule[i] - schedule[i - 1] - 1);
    }
    return min(mn, max(d - schedule.back() - 1, (mx - 1) / 2));
}


void solve() {
	int n, d;
	cin >> n >> d;

	int ans = INT_MAX;
	int pos = 0, mn = INT_MAX;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] - a[i - 1] - 1 < mn) {
			pos = i;
			mn = a[i] - a[i - 1] - 1;
		}
	}
	ans = mn;

	vector<int> tmp;
	for (int i = 0; i <= n; i++) {
		if (i != pos) {
			tmp.push_back(a[i]);
		}
	}
	ans = max(ans, cnt(tmp, d, n));

	if (pos > 1) {
		tmp[pos - 1] = a[pos];
	}

	ans = max(ans, cnt(tmp, d, n));
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