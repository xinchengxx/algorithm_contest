#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
	string s;
	cin >> s;
	int i = 0;
	while (i < s.size()) {
		int j = i + 1;
		while (j < s.size() && s[j] == s[i]) j++;
		// i...j - 1
		int t = j - i;
		if (t == 1) {
			cout << "No\n";
			return;
		}
		i = j;
	}
	cout << "Yes\n";
    // 1000011100
    // 1000011000
    // 1000010100
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}	
	return 0;
}