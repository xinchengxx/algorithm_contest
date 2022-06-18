#include <bits/stdc++.h>
using namespace std;
// 118D Caesar's Legions
const int mod = 1e8;
int f[105][105][2]; // 0 表示 第一个是 footman, 1 表示第一个是horseman 
// 关键在于dp不要太限制死了维度
// 就像本题是一个三维的dp;
// 就像本题(n1 + n2) ^ 2 的时间复杂度
// 考虑f[n1][n2]是两维度
// 然后考虑前面第一个是horseman 还是 footman的情况
// 所以是三维
// 然后需要好好考虑状态转移
// 这里通过考虑前面诺干个是一种类型的情况(关键是转化为求解子问题的情况)  
// 所以我们列出来的状态转移返方程式;
// f[n1][n2][0] = f[n1 - 1][n2][1] + f[n1 -2][n2][1]+ ...... + f[n1 - min(n1, k1)][n2][1];
// f[n1][n2][1] = f[n1][n2 - 1][0] + ...... f[n1][n2 - min(n2, k2)][0] 
int n1, n2, k1, k2;
int main() {
	scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
	// 但是这个是现有 
	for (int i = 1; i <= k1; i++) {
		f[i][0][0] = 1;
	}
	for (int i = 1; i <= k2; i++) {
		f[0][i][1] = 1;
	}
	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			for (int k = 1; k <= min(i, k1); k++) {
				f[i][j][0] += f[i - k][j][1];
				f[i][j][0] %= mod;
			}
			for (int k = 1; k <= min(j, k2); k++) {
				f[i][j][1] += f[i][j - k][0];
				f[i][j][1] %= mod;
			}
		}
	}
	int ans = (f[n1][n2][0] + f[n1][n2][1]) % mod;
	printf("%d", ans);
	return 0;
}
