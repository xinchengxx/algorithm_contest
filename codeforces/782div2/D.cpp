#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


void solve() {
	int n;
	cin >> n; 

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int cur = 0;
	vector<int> ans(n + 1, -1);
	vector<int> pos(n + 1, -1); // 记录第i个0的位置
	int i = 0;
	while (i < n && a[i] == 0) {
		ans[i] = 0;
		pos[i + 1] = i;
		i++;
	}

	// 列出公式会更加的清晰
	for (; i < n; i++) {
		if (ans[i] == 0) {
			pos[i + 1] = a[i] + i;
			for (int j = pos[i] + 1; j < pos[i + 1]; j++) {
				ans[j] = 1;
			}
			ans[pos[i + 1]] = 0;
		} else {
			//pos[i + 1] - 1 - 0 + 1 = a[i];
			pos[i + 1] = a[i];
			for (int j = pos[i] + 1; j < pos[i + 1]; j++) {
				ans[j] = 1;
			}
			ans[pos[i + 1]] = 0;
		}
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << "\n";
}


int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}