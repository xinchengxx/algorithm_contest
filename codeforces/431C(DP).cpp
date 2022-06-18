#include<bits/stdc++.h>
using namespace std;

// 但是它是一个无穷的树
// 然后有明显的子问题
int n, k, d; 
// 如果采用dfs的话,每次减一的情况会卡内存;
// 所以不对
// 注意我在思考一下;
// 如何使用dp优化
// 关键在于dp的状态设计
// f[i][j] 可以表示总和为i, 且至少为j的方案书
// 如果i <= j
// f[i][j] = 0;
int mod = 1e9 + 7;
int f[105][105];
// 还是得先写状态转移方程;
// f[i][j] = f[i - 1][j] + f[i - 2][j] ..... f[i - j + 1][j]
// f[i - j][1] + ...... f[i - k][1];
// 因为d是一个常数欸; 
int main() {
	// 大概有点思路;
	scanf("%d%d%d", &n, &k, &d);
	f[1][1] = 1;
	f[0][1] = 1;
	f[0][d] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j > i) break;
			f[i][1] += f[i - j][1]; 
			f[i][1] %= mod; 
		}
	}
	if (d != 1) {
	for (int i = 1; i < d; i++)
		f[i][d] = 0;
	for (int i = d ; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j > i)
				continue;
			if (j < d) {
				f[i][d] += f[i - j][d];
				f[i][d] %= mod;
			} else {
				f[i][d] += f[i - j][1];
				f[i][d] %= mod;
			}
		}
	}
}
	// 注意答案的做法,和我的做法其实本质上一样
	// 它设定的状态在于f[i][is] if is == 1,表明统计的是路径有>= d的边, 否则就是没有 
	printf("%d", f[n][d]);
	return 0;
}
