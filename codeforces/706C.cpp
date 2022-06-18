#include<bits/stdc++.h>
using namespace std;

// 706C Hard Problem
const int MAX = 100000 + 5;
// 好好分析状态
// 由于顺序不能变化;
//	dp的关键在于不去想后面, 即唯一确定依赖于前面

// 那么很简单了
long long f1[MAX], f2[MAX];
int cost[MAX];
int main() {
	// f1表示第i 个不反转;
	// f2表示第i 个反转的最小分数;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cost[i]);
	} 
	// 只需要记录上两个;
	string now, lst, now_rev, lst_rev;
	cin >> now;
	now_rev = now;
	reverse(now_rev.begin(), now_rev.end());
	memset(f1, 0x3f, sizeof(f1));
	memset(f2, 0x3f, sizeof(f2));
	f1[1] = 0;
	f2[1] = cost[1];
	for (int i = 2; i <= n; i++) {
		// 看情况;
		lst_rev = now_rev;
		lst = now;
		cin >> now;
		now_rev = now;
		reverse(now_rev.begin(), now_rev.end());
		// 解析来判定;
		bool flag = true;
		if (now >= lst_rev) {
			f1[i] = min(f1[i], f2[i - 1]);
			flag = false;
		} 
		if (now >= lst) {
			f1[i] = min(f1[i], f1[i - 1]);
			flag = false;
		}
		if (now_rev >= lst_rev) {
			f2[i] = min(f2[i], f2[i - 1] + (long long)cost[i]);
			flag = false;
		}
		if (now_rev >= lst) {
			f2[i] = min(f2[i], f1[i - 1] + (long long)cost[i]);
			flag = false;
		}
		if (flag) {
			printf("-1");
			return 0; 
		}
	}
	printf("%lld", min(f2[n], f1[n]));
	return 0;
} 
