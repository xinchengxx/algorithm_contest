#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		int ans = 0;
		for (int i = 1; i < n; i++) {
			if (s[i] == '1') continue;
			else {
				// ....0
				if (s[i - 1] == '0') {
					ans += 2;
					continue;
				} else {
					if (i == 1)
						continue;
					if (s[i - 2] == '1') continue;
					else {
						//....010
						ans += 1;
						continue;
					}
				}
			}
 		}
 		printf("%d\n", ans);
	}
}
