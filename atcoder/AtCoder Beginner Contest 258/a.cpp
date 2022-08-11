#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	int k;
	cin >> k;
	int mi = k % 60;
	int h = k / 60;
	if (mi < 10) {
		cout << 21 + h << ":0" << mi << endl;
	} else {
		cout << 21 + h << ":" << mi << endl;
	}
}