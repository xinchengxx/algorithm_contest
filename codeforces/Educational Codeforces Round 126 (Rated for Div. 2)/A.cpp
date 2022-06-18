#include <bits/stdc++.h>
using namespace std;
int t;

void solve() {
	int n;
	cin >> n;
	vector<long long> a(n), b(n);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
		cin >> b[i];
	long long ans = 0;
	// 只用看后面
	for (int i = 0; i < n - 1; i++) {
		if ((long long)abs(a[i] - a[i + 1]) + (long long)abs(b[i] - b[i + 1]) > (long long)abs(b[i] - a[i + 1]) + (long long)abs(a[i] - b[i + 1])) {
			ans += (long long)abs(b[i] - a[i + 1]) + (long long)abs(a[i] - b[i + 1]) ;
		} else {
			ans += (long long)abs(a[i] - a[i + 1]) + (long long)abs(b[i] - b[i + 1]);
		}
	}
	// 如果增大了
	cout << ans << endl;
}


int main() {
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}