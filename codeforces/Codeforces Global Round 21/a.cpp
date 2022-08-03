#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, z;
	cin >> n >> z;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = a[i] | z;
	}
	cout << *max_element(a.begin(), a.end()) << endl;
	
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}