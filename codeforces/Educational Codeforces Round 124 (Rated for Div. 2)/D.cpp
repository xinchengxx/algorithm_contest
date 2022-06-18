#include <bits/stdc++.h>
using namespace std;


inline int read() {
	int s = 1, t = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') s = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		t = t * 10 + ch - '0';
		ch = getchar();
	}
	return s * t;
} 

int n;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
// yeah, I have a deep understanding of the {} expression

int main() {
	n = read(); // 
	vector<pair<int, int>> a;
	for (int i = 1; i <= n; i++) {
		int x = read(), y = read();
		a.push_back({x, y});
	}
	queue<pair<int, int>> q;
	set<pair<int, int>> st(a.begin(), a.end()); // nlogn
	map<pair<int, int>, pair<int, int>> ans; 
	// s.count(); // map, set, multiset, multimap is rb tree, therefor the time complexity is logn 
	// for operations of inserting, deleting, finding
	for (int i = 0; i < a.size(); i++) {
		int x = a[i].first, y = a[i].second;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (st.count({nx, ny})) continue;
			q.push({x, y});
			ans[{x, y}] = {nx, ny}; // 重载了等于号
			break; //  
		}
	}
	
	
	while (!q.empty()) {
		auto it = q.front();
		int x = it.first, y = it.second;
		q.pop(); // BFS, 考虑一下 
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (!st.count({nx, ny}) || ans.count({nx, ny})) {
				continue;
			}
			q.push(make_pair(nx, ny));
			ans[{nx, ny}] = ans[{x, y}];
		}
	}
	for (int i = 0; i < n; i++) {
		auto it = ans[a[i]];
		printf("%d %d\n", it.first, it.second);
	}
	return 0;
}
