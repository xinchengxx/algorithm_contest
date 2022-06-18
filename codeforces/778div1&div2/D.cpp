// 这个题实在是牛逼... 好好学习一下
#include <bits/stdc++.h>
using namespace std;
#define ll long long


const int N = 2e5 + 10, lim = 2e5;
const ll mod = 998244353;

// 如何记录...使用一个divisor记录因子 num 记录个数; 
vector<int> d[N], num[N];

vector<int> son[N], xval[N], yval[N];  // 记录树可以这样

int f[N], g[N]; // f记录现在的

ll ans = 0;
int t, n, x, y, xx, yy; 

inline int read() {
	bool flag = false; 
	int tot = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') flag = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		tot = tot * 10 + ch - '0';
		ch = getchar();
	}
	return flag == true ? -tot : tot;
}

// 埃氏筛 unicode 
void init() {
	for (int i = 2; i <= lim; i++) {
		int c = i;
		for (int j = 2; j * j <= c; j++) {
			int cnt = 0;
			while (c % j == 0) {
				cnt++;
				c /= j;
			}
			if (cnt) {
				d[i].push_back(j);
				num[i].push_back(cnt);
			}  
		}
		// 注意好好理解the seive of Eratosthenes 
		if (c > 1) {
			d[i].push_back(c);
			num[i].push_back(1);
		}
	}
}
// quick power
inline ll power(int x, int k) {
	ll ans = 1, base = x;
	while (k) {
		if (k & 1) {
			ans = ans * base % mod;
		}
		// %的优先级 
		base = base * base % mod;
		k >>= 1; 
	}
	return ans;
}
void dfs1(int u, int fa) {
	for (int i = 0; i < son[u].size(); i++) {
		int v = son[u][i]; 
		if (v == fa) continue;
		int w = xval[u][i];
		// 这个是logn级别的 
		for (int j = 0; j < d[w].size(); j++) {
			f[d[w][j]] -= num[w][j];
		}
		w = yval[u][i];
		for (int j = 0; j < d[w].size(); j++) {
			f[d[w][j]] += num[w][j];
			g[d[w][j]] = max(g[d[w][j]], f[d[w][j]]);
		}
		dfs1(v, u);
		// backtrack
		for (int j = 0; j < d[w].size(); j++) {
			f[d[w][j]] -= num[w][j];
		}
		w = xval[u][i];
		for (int j = 0; j < d[w].size(); j++) {
			f[d[w][j]] += num[w][j];
		}
	}
}

void dfs2(int u, int fa, ll w) {
	ans += w;
	ans %= mod;
	for (int i = 0; i < son[u].size(); i++) {
		int v = son[u][i];
		if (v == fa) continue;
		// u->v u 
		// 为什么使用这个mod的原因是为了解决除数的问题 
		// a * power(y, mod - 2) = a / y 同余.....  由费马小定理可得, 算是一个狗坑了 
		dfs2(v, u, w * xval[u][i] % mod * power(yval[u][i], mod - 2) % mod);
	} 
}

int main() {
	t = read();
	init();
	while (t--) {
		n = read();
		ans = 0;
		for (int i = 0; i <= n; i++) {
			g[i] = 0, f[i] = 0;
			son[i].clear(), xval[i].clear(), yval[i].clear(); 
		}
		for (int i = 1; i <= n - 1; i++) {
			x = read(), y = read(), xx = read(), yy = read();
			int gcd = __gcd(xx, yy); // 还要除掉最大公因数, 可以节约时间 
			xx /= gcd, yy /= gcd;
			son[x].push_back(y);
			xval[x].push_back(yy);    
			yval[x].push_back(xx);
			son[y].push_back(x);
			xval[y].push_back(xx);
			yval[y].push_back(yy);
			// x->y => y = x * yy / xx  , xval在上面 
		}
		dfs1(1, 0);
		ll w = 1;
		// 注意初始化的问题 
		for (int i = 2; i <= n; i++) {
			w = w * power(i, g[i]) % mod;
		}
		dfs2(1, 0, w);
		printf("%lld\n", ans);
	}
	return 0;
}


