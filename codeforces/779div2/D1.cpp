#include <bits/stdc++.h>
using namespace std;
// 肯定只能是n的时间复杂度了, 10^6
int t;

void solve() {
	// 关键在于为什么捏...
	// 如果是

	// 关键在于........ 当0 和 1一样的时候是怎么样的捏.. x ^ (1 << i) 也一定在..
	//
	//
	int l, r; 
	cin >> l >> r;
	vector<int> cnt1(32), cnt0(32);
	for (int i = 0; i <= (r - l); i++) {
		int val;
		cin >> val;
		for (int j = 0; j < 32; j++) {
			if (val & 1) {
				cnt1[j]++;
			} else {
				cnt0[j]++;
			}
			val >>= 1;
		}
	}
	int num = 0;
	for (int i = 0; i < 32; i++) {
		// 1多说明要翻转
		if (cnt1[i] > cnt0[i]) {
			num = num ^ (1 << i);
		} 
	} 
	cout << num << "\n";
}

int main() {
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

