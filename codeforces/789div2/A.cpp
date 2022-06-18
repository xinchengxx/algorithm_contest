#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	int cnt = 0;
	vector<int> a(n);
	unordered_set<int> st;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (st.count(a[i]) || a[i] == 0) {
			flag = true;
		}
		st.insert(a[i]);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i]) {
			ans++;
		}
	}
	if (!flag) ans++;
	cout << ans << "\n";

}


int t;
int main() {
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}