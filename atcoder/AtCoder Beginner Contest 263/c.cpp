#include<bits/stdc++.h>
using namespace std;
using i64 = long long;



int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a;
	function<void(int)> dfs = [&](int cur) {
		if (a.size() == n) {
			for (int i = 0; i < n; i++) {
				cout << a[i] << " \n"[i == n - 1];
			}
			return;
		}
		for (int i = cur; i <= m; i++) {
			a.push_back(i);
			dfs(i + 1);
			a.pop_back();
		}
	};
	dfs(1);
	return 0;
}