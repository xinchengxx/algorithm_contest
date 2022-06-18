#include<bits/stdc++.h>
using namespace std;
int t;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> t;
	while (t--) {
		string str;
		int ans = 0;
		cin >> str;
		int l = 0, r = 1; // r表示还没开始的
		unordered_set<char> st;
		st.insert(str[0]);
		while (r < str.size()) {
			if (st.count(str[r])) {
				ans += r - l - 1;
				l = r + 1;
				r = l + 1;
				st.clear();
				st.insert(str[l]);
				continue;
			} 
			st.insert(str[r]);
			r++;
		}
		if (l < str.size()) {
			// 剩下的都不要了...
			ans += str.size() - l;
		} 
		printf("%d\n", ans);
	}
	return 0;
}
