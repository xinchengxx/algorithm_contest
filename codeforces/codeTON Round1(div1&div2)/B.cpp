#include <bits/stdc++.h>
using namespace std;

int t;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	int l = 0, r = 1;
	while (r < n) {
		while (r < n && arr[r] - arr[l] < k) r++;
		if (r == n) break;
		if (arr[r] - arr[l] == k) {
			cout << "YES\n";
			return ;
		}
		l++;
	}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}