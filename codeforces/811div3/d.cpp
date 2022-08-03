#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n;
	string t;
	cin >> t >> n;

	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = 0;
	int len = t.size();
 	
 	int l = 0, r = -1;
 	vector<pair<int, int>> p;
 	for (int i = 0; i < len; i++) {
 		string tmp = t.substr(0, i + 1);
 		for (int k = 0; k < n; k++) {
 			if (a[k] == tmp) {
 				if (r == -1) {
 					r = i;
 					ans++;
 					p.push_back({k + 1, 1});
 				} else {
 					r = i;
 					p.back().first = k + 1;
 				}
 			}
 		}
 	}
 	//cout << l << " " << r << endl;
 	if (r == -1) {
 		cout << -1 << endl;
 		return;
 	}
 	while (r < len - 1) {
 		int mx = -1, nx = -1;
 		for (int i = l + 1; i <= r + 1; i++) {
 			for (int j = i; j < len; j++) {
 				string tmp = t.substr(i, j - i + 1);
 				for (int k = 0; k < n; k++) {
 					if (a[k] == tmp && j > mx) {
 						if (mx == -1) {
 							nx = i, mx = j;
 							ans++;
 							p.push_back({k + 1, i + 1});
 						} else {
 							nx = i, mx = j;
 							p.back().first = k + 1;
 							p.back().second = i + 1;
 						}
 					}
 				}
 			}
 		}
 		
 		if (mx == -1) {
 			cout << -1 << endl;
 			return;
 		}
 		l = nx, r = mx;
 	}
 	cout << ans << endl;
 	for (int i = 0; i < p.size(); i++) {
 		cout << p[i].first << " " << p[i].second << endl;
 	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}