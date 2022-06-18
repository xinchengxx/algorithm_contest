#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	i64 ans = n;
	// 不算一个字符的;
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i - 1]) {
			// 0....i
			ans += i;
		}
	}
	// 统计AXXXA的情况;

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