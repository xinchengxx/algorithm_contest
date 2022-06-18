#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


void solve() {
	string s;
	cin >> s;

	string sub;
	vector<int> cnt(26);
	int i = 0;
	while (i < s.size()) {
		if (cnt[s[i] - 'a'] == 1) {
			break;
		}
		cnt[s[i] - 'a']++;
		sub += s[i];
		i++;
	}

	//cout << sub << endl;
	int cur = 0;
	while (i < s.size()) {
		if (s[i] != sub[cur]) {
			cout << "No\n";
			return;
		}
		i++, cur++;
		if (cur == sub.size()) {
			cur = 0;
		}
	}

	cout << "Yes\n";
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}
