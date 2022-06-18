#include <bits/stdc++.h>
using namespace std;
int t, n;

vector<int> a(2e5 + 10);

// haohaoxiangxiang
// if the is n;
// 5->1->5->2->5->2->5->?
//5->?

// it-is非常像
// 和那个题很像, 就是挑出n个球不相邻的情况, 考虑最大的, yes it is

// 考虑最大的和其他的, if a >= sum + 1, ans = 2 * sum + 1, ans = a - sum, 
// if a < sum,  // x1 x2 x3.....xn - 1 x1 x2.......xn-1 ............x1 - x2 - x....xn - 1
// < a那么就有一种策略...最后随便补一个就好了 

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		a.clear();
		bool flag = false;
		long long sum = 0;
		int ma = INT_MIN;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			sum += a[i];
			if (a[i]) flag = true;
			ma = max(ma, a[i]);
		}
		if (flag == false) {
			cout << 0 << endl;
			continue;
		}
		// 2->1->2->3->2
		sum -= ma;
		if (sum >= ma) printf("1\n");
		else {
			long long ans = ma - sum;
			printf("%lld\n", ans);
		}	
	}
	return 0;
}
