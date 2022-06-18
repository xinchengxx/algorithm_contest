#include <bits/stdc++.h>
using namespace std;

int n, k;
const int MAX = 200000 + 5;
vector<int> ee[MAX];
int depth[MAX], siz[MAX];

// 为什么这样就是对的
// 好好想一下
// 那么假设已经对了
//	industry -> tourism  
//  n - k 
//  由于的
//  how to think about this 

void dfs(int u, int fa) {
	depth[u] = depth[fa] + 1;
	siz[u] = 1;
	for (int i = 0; i < ee[u].size(); i++) {
		int v = ee[u][i];
		if (v == fa) continue;
		dfs(v, u);
		siz[u] += siz[v];
	}
}
int arr[MAX];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		// u == from , v == to remember;
		ee[u].push_back(v);
		ee[v].push_back(u); 
	}
	// 考虑一下如果
	// 因为要选择n - k 个为
	// 注意此处根是1 
	dfs(1, 0); 
	for (int i = 1; i <= n; i++) {
		arr[i] = siz[i] - depth[i]; 
	}
	// 注意一下sort函数的用法 
	// sort是左闭右开的地址 
	// 以及本题的思考过程, 可以考虑为一开始全是工业化然后选择n - k 发展tourism, 并且利用那个贪心考虑如何选择
	// 才会比较优秀 
	sort(arr + 1, arr + 1 + n, greater<int>());
	long long ans = 0;
	for (int i = 1; i <= n - k; i++) {
		ans += arr[i];
	}
	printf("%lld", ans);
	return 0;
}
