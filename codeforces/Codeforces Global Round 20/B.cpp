#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	int t1 = 0, t2 = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A') t1++;
		else { 
			t2++;
		}
		if (t1 < t2) {
			cout << "No\n";
			return ;
		}
	}
	if (t2 == 0 || s[s.size() - 1] != 'B') {
		cout << "No\n";
		return;
	}
	// 如果是插入的话
	// A..AAB....B
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

