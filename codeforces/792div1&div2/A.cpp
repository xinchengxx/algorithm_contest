#include <bits/stdc++.h>
using namespace std;

void solve() {
	string num;
	cin >> num;

	if (num.size() == 2) {
		cout << num[1] << endl;
		return ;
	} 
	char c = *min_element(num.begin(), num.end());
	cout << c << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}