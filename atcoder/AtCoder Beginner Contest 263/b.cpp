#include<bits/stdc++.h>
using namespace std;
using i64 = long long;



int main() {
	int n;
	cin >> n;
	vector<int> p(n + 1);
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
	}
	int ans = 0;
	while (n) {
		ans++;
		n = p[n]; 
	}
	cout << ans - 1 << endl;
	return 0;
}