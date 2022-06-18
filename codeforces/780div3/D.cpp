#include<bits/stdc++.h>
using namespace std;
int t;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		// f1是当前最大的2的个数 
		vector<int> f1(n + 1), f2(n + 1), s1(n + 1), s2(n + 1), arr(n + 1); 
		int id = 0, mx = 0; // 记录2的数量 
		f1[0] = f2[0] = 0;
		s1[0] = s2[0] = 1; //默认符号 
		for (int i = 1; i <= n; i++) {
			int a;
			cin >> a;
			arr[i] = a;
			if (a == 0) {
				f1[i] = 0;
				s1[i] = 1;
				f2[i] = 0;
				s2[i] = 1;
				continue;
			} 
			if (a < 0) {
				if (arr[i] == -2) {
					// f1 => f2;
					if (s2[i - 1] == 1) {
						// f2[i - 1]是个
						f1[i] = 1;
						s1[i] = -1; 
						// 之前-的最多的还是正数... 
						// 如果之前-的最多是个整数... 
					} else {
						// 是负数;
						f1[i] = f2[i - 1] + 1;
						s1[i] = 1; 
					}
					if (s1[i - 1] == -1) {
						// 之前正的最多的是个负数, 正的最多是个负数...===>  
						f2[i] = 1;
						s2[i] = -1; 
					} else {
						f2[i] = f1[i - 1] + 1;
						s2[i] = -1; // 我要求最小的... 如果之前正的最多的是个负数.. 
					}
				} else {
					if (s2[i - 1] == 1) {
						//如果之前fu的最多的是个正数...
						f1[i] = 0;
						s1[i] = -1; 
					} else {
						f1[i] = f2[i - 1];
						s1[i] = 1;
					} 
					if (s1[i - 1] == -1) {
						f2[i] = 0;
						s2[i] = -1; 
					} else {
						f2[i] = f1[i - 1];
						s2[i] = -1;
					}
				}
			} else {
				if (arr[i] == 2) {
					if (s1[i - 1] == 1) {
						f1[i] = f1[i - 1] + 1;
						s1[i] = 1;
					} else {
						f1[i] = 1;
						s1[i] = 1;
					}
					if (s2[i - 1] == 1) {
						f2[i] = 1;
						s2[i] = 1;
					} else {
						f2[i] = f2[i - 1] + 1;
						s2[i] = -1;
					}
				} else {
					if (s1[i - 1] == 1) {
						f1[i] = f1[i - 1];
						s1[i] = 1;
					} else {
						f1[i] = 0;
						s1[i] = 1;
					} 
					if (s2[i - 1] == 1) {
						f2[i] = 0;
						s2[i] = 1; 
					} else {
						f2[i] = f2[i - 1];
						s2[i] = -1;
					}
				} 
			}
			if (f1[i] > mx && s1[i] == 1) {
				mx = f1[i];
				id = i;
			}
		}
		if (mx == 0) {
				printf("%d 0\n", n);
			} else {
				int tot = 0, sign = 1;
				for (int i = id ; i >= 1; i--) {
					if (arr[i] < 0) {
						sign *= -1;
					} 
					if (abs(arr[i]) == 2) {
						tot++;
					}
					if (tot * sign == mx) {
						printf("%d %d\n",i - 1, n - id);
						break;
					}
				}
			} 
	}
	return 0;
}
