#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n;
	cin >> n;
	// 要想让前面尽可能小.. 后面就得尽可能大;
	string ans;
	for (int i = 9; i >= 1; i--) {
		if (n < i) continue;
		if (n >= i) {
			n -= i;
			ans.push_back(i + '0');
		}
	}
	reverse(ans.begin(), ans.end());
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