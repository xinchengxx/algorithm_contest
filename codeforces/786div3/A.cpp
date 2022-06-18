#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int t;

int main() {
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		if (y % x != 0) {
			cout << 0 << " " << 0 << endl;
			continue;
		}
		int b = y / x, a = 1;
		cout << a << " " << b << endl;
		
	}

	return 0;
}