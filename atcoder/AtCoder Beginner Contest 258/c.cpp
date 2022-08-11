#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	int n, q;
	cin >> n >> q;
	string str;
	cin >> str;
	i64 tot = 0;
	// -tot;
	for (int i = 1; i <= q; i++) {
		int op, num;
		cin >> op >> num;
		if (op == 1) {
			tot += num;
		} else {
			num--;
			cout << str[((num - tot % n) + n) % n] << "\n";
		}
	}
	return 0;
}