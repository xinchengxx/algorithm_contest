#include <bits/stdc++.h>
using namespace std;
const int mod = 32768;

int main() {
	int n;
	
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	// 0 32768 / 2 
	unordered_map<int, int> ans;
	unordered_set<int> st;
	queue<pair<int, int>> q;
	q.push({32767, 1});
	q.push({16384, 1});
	ans[32767] = 1;
	ans[16384] = 1;
	st.insert(32767);
	st.insert(16384);
	while (!q.empty()) {
		auto it = q.front();
		int cur = it.first, time = it.second;
		q.pop();
		if (cur % 2 == 0) {
			// 某个cur / 2 * 2
			if (!st.count(cur / 2)) {
				q.push({cur / 2, time + 1});
				ans[cur / 2] = time + 1;
				st.insert(cur / 2);
			}
			if (!st.count((cur + mod) / 2)) {
				q.push({(cur + mod) / 2, time + 1});
				ans[(cur + mod) / 2] = time + 1;
				st.insert((cur + mod) / 2);
			}
			// t * 2 = (cur + mod) 
		} 
		if (cur - 1 >= 0) {
			if (!st.count(cur - 1)) {
				q.push({cur - 1, time + 1});
				ans[cur - 1] = time + 1;
				st.insert(cur - 1);
			}
		}
	}
	ans[0] = 0;
	for (int i = 0; i < n; i++)
		cout << ans[a[i]] << " ";
	return 0;
}