#include<bits/stdc++.h>
using namespace std;
int t;

// 本题的关键在于一个trick
// 注意[l, r] = r - l + 1的一个trick
// 我们仅考虑半闭区间(half-closed interval) 
// 并且令Pi = [0, i)
// 那么[l, r] = r - l + 1 == Pr - Pl = r - l 
// ===> Pr - r = Pl - r
// 然后统计就好了  
int sum[100000 + 5];
 
int main() {
	scanf("%d", &t);
	while(t--) {
		int n;
		string nums;
		cin >> n >> nums;
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; i++) {
			sum[i] = sum[i - 1] + nums[i - 1] - '0';
		}
		// 接下来该如何统计呢
		unordered_map<int, int> ma;
		for (int i = 0; i <= n; i++) {
			int val = sum[i] - i;
			ma[val]++;
		} 
		long long ans = 0;
		// unordered_map的一种遍历方式 
		for (auto& v : ma) {
			long long val = v.second;
			ans += (val) * (val - 1) / 2; 
 		}
 		printf("%lld\n", ans); // 注意这个整数溢出的问题, 以及这个%lld 
	}
	return 0;
}
