#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	int ans = 0, seg = 0;

	string prev;
	for (int i = 0; i < s.size(); i += 2) {
		string tmp = s.substr(i, 2);
		if (tmp == "01" || tmp == "10") {
			ans++;
		} else {
			if (tmp == "11") {
				if (prev == "" || prev == "00") {
					seg++;
				}
				prev = "11";
			} else {
				if (prev == "" || prev == "11") {
					seg++;
				} 
				prev = "00";
			}
		}
	}
	if (seg == 0) seg = 1;
	cout << ans << " " << seg << endl;
}


int t;
int main() {
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}