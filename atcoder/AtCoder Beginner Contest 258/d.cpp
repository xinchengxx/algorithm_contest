#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	int n, x;
	cin >> n >> x;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	i64 ans = 1e20;
	priority_queue<int, vector<int>, greater<int>> pq;
	i64 tot = 0;
	for (int i = 0; i < min(n, x); i++) {
		pq.push(a[i].second);
		int last = x - i - 1;
		tot += ((i64)a[i].first + a[i].second);
		i64 sum = tot;
		sum += 1ll * pq.top() * last;
		ans = min(ans, sum);
	}
	cout << ans << "\n";
	return 0;
}