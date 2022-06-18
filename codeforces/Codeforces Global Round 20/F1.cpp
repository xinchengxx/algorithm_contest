#include <bits/stdc++.h>
using namespace std;


void solve() {
	int n;
	cin >> n;


	vector<int> a(n);
	vector<int> cnt(n);
	vector<vector<int>> f(n); 
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		f[cnt[a[i]]].push_back(i);
		cnt[a[i]]++;
	}	
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		if (!f[i].empty()) {
			int k = f[i].size();
			sort(f[i].begin(), f[i].end(), [&](int i, int j) { return a[i] < a[j]; });
			for (int j = 0; j < k; j++) {
				b[f[i][j]] = a[f[i][(j + 1) % k]];
				b[f[i][j]]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << b[i] << " \n"[i == n - 1];
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