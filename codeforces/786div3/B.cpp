#include <bits/stdc++.h>
using namespace std;
using i64 = long long;



map<string, int> s;
int t;

void solve() {
	string str;
	cin >> str;
	cout << s[str] << endl;
}


int main() {
	cin >> t;

	int idx = 1;
	for (char c = 'a'; c <= 'z'; c++) {
		for (char d = 'a'; d <= 'z'; d++) {
			if (d != c) {
				string word;
				word.push_back(c);
				word.push_back(d);

				s.insert({word, idx++});
			}
		}
	}
	while (t--) {
		solve();
		
	}

	return 0;
}