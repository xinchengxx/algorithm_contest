#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	set<int> st;
	for (int i = n - 1; i >= 0; i--) {
		if (st.count(a[i])) break;
		st.insert(a[i]);
	}
	cout << n - st.size() << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}