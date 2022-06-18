#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 lcm(i64 res, i64 a) {
	return res * a / __gcd(res, a);
}
void solve() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}

	vector<bool> vis(n, false);
	i64 ans = 1;
	for (int i = 0; i < n; i++) {
		if (vis[i] == true) continue; 
		else {
			int times = 1;
			int nxt = p[i];
			string tmp;
			tmp.push_back(s[i]);
			vis[i] = true;
			while (nxt != i) {
				times++;
				tmp.push_back(s[nxt]);
				vis[nxt] = true;
				nxt = p[nxt];
			}
			int j = 1;
			string before = tmp;
			for (j = 1; j <= times; j++) {
				rotate(tmp.begin(), tmp.begin() + 1, tmp.end());
				if (tmp == before) {
					ans = lcm(ans, j);
					break;	
				}			
			}
		}
	}
	
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