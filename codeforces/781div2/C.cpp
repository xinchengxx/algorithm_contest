#include <bits/stdc++.h>
using namespace std;

int t;
void solve() {
	int n;
	cin >> n;
	vector<vector<int>> son(n + 1, vector<int>());
	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		son[p].push_back(i);
	}
	int ans = 0;
	sort(son.begin(), son.end(), [&](const vector<int>& a, const vector<int>& b) {
		return a.size() > b.size();
	});
	// 一开始最优的策略就是一路加下去
	priority_queue<int> pq;
	int m1 = 0;
	int i;
	for (i = 0; i < son.size(); i++) {
		if (son[i].size() == 0)
			break;
		pq.push(i + (int)son[i].size() - 1);
	}
	m1 = pq.top();
	if (m1 <= i) {
		m1 = i;
	} else {
		int cur = i;
		vector<int> arr;
		while (!pq.empty()) {
			if (pq.top() <= cur) break;
			arr.push_back(pq.top() - cur);
			pq.pop();
		}
		//arr.push_back(pq.top() - cur);
		// 最少需要的时间
		int l = 1, r = arr[0];
		int add = r;
		// mid 表示额外需要的时间
		while (l <= r) {
			int mid = (l + r) >> 1;
			// mid 认为是需要的时间
			long long tot = 0;
			for (int i = 0; i < arr.size(); i++) {
				if (arr[i] <= mid) {
					break;
				} else {
					tot += arr[i] - mid;
				}
			} 
			if (tot <= mid) {
				add = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		m1 = cur + add;
	}
	cout << m1 + 1 << endl;
}

int main() {
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}