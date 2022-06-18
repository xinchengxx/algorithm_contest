#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


void solve() {
	int n;
	cin >> n;

	vector<int> digit1(26);
	for (int i = 0; i < 2 * n; i++) {
		string s;
		cin >> s;
		for (auto& ch : s) {
			digit1[ch - 'a']++;
		}
	}

	string ans;
	vector<int> digit2(26);
	cin >> ans;
	for (auto& ch : ans) {
		digit2[ch - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		//cout << digit1[i] << " " << digit2[i] << endl;
		if (digit1[i] == 0) continue;
		if (digit1[i] % 2 != digit2[i] % 2) {
			char t = 'a' + i;
			cout << t << endl;
			return;
		}
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}