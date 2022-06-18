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

	int l = a[0];
	int i;
	for (i = 1; i < n; i++) {
		if (abs(a[i] - (l + i)) >= 2) {
			break;
		}
	}
	if (i == n) {
		cout << "Yes\n";
		return;
	}
	l = a[0] + 1;
	for (i = 1; i < n; i++) {
		if (abs(a[i] - (l + i)) >= 2) {
			break;
		}
	}
	if (i == n) {
		cout << "Yes\n";
		return;
	}
	l = a[0] - 1;
	for (i = 1; i < n; i++) {
		if (abs(a[i] - (l + i)) >= 2) {
			break;
		}
	} 
	if (i == n) {
		cout << "Yes\n";
		return ;
	}

	cout << "No\n";

}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}	
	return 0;
}