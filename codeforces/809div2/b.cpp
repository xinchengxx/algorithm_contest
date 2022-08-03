#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


// 相当于一个套路, 有点类似dp 和贪心的思想, 本质是求奇偶交替的
// 最长序列
void solve() {
	int n;
	cin >> n;
	//vector<int> a(n);
	vector<int> lst(n + 1, -1);
	vector<int> cnt(n + 1);
	for (int i = 0; i < n; i++) {
		int color;
		cin >> color;
		if (lst[color] == -1 || (lst[color] % 2) != i % 2) {
			cnt[color]++;
			lst[color] = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << cnt[i] << " \n"[i == n];
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