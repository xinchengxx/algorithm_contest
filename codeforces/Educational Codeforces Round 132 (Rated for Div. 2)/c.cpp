#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	string s;
	cin >> s;

	// 本题思想上有两个核心, 一是对于rbs的判断是不断判断左边>= 右边....
	// 所有最完美的贪心就是交换末置位的两个;
	int n = s.size() / 2;
	int open = n - count(s.begin(), s.end(), '('), close = n - count(s.begin(), s.end(), ')');
	if (open == 0 || close == 0) {
		cout << "Yes\n";
		return;
	}
	int cur = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '?') {
			if (cur < open - 1 || cur == open) {
				s[i] = '(';
			} else {
				s[i] = ')';
			}
			cur++;
		}
	}
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		cnt += s[i] == '(' ? 1 : -1;
		if  (cnt < 0) {
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
} 

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}