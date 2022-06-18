#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int t;

void solve() {
	string a, b;
	cin >> a >> b;
	
	if (b == "a") {
		cout << 1 << endl;
		return;
	} else if (count(b.begin(), b.end(), 'a')) {
		cout << -1 << endl;
		return;
	}
	long long ans = 1;
	ans = ans << (int)a.size(); 
	cout << ans << endl;
}


int main() {
	cin >> t;
	while (t--) {
		solve();
		
	}

	return 0;
}