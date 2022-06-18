#include<bits/stdc++.h>
using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;

	string ans;
	int t = min(a, b);
	for (int i = 0; i < min(a, b); i++) {
		ans += '0';
		ans += '1';	
	}
	if (t < a) {
		for (int i = 0; i < a - t; i++) 
			ans += '0';
	} else {
		for (int i = 0; i  < b - t; i++) 
			ans += '1';
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}