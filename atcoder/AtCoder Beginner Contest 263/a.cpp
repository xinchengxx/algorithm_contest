#include<bits/stdc++.h>
using namespace std;
using i64 = long long;



int main() {
	vector<int> buck(14);
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	buck[a]++, buck[b]++, buck[c]++, buck[d]++, buck[e]++;
	bool two = false, three = false;
	for (int i = 1; i <= 13; i++) {
		if (buck[i]) {
			if (buck[i] == 2) two = true;
			if (buck[i] == 3) three = true;
		}
	}
	if (two && three) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}