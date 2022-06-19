
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 10, lim = 2e5;
const ll mod = 998244353;

vector<int> d[N], num[N];

vector<int> son[N], xval[N], yval[N];

int f[N], g[N];

ll ans = 0;
int t, n, x, y, xx, yy;

inline int read() {
    bool flag = false;
    int tot = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            flag = true;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        tot = tot * 10 + ch - '0';
        ch = getchar();
    }
    return flag == true ? -tot : tot;
}

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
        if (c > 1) {
            d[i].push_back(c);
            num[i].push_back(1);
        }
    }
}

inline ll power(int x, int k) {
    ll ans = 1, base = x;
    while (k) {
        if (k & 1) {
            ans = ans * base % mod;
        }

        base = base * base % mod;
        k >>= 1;
    }
    return ans;
}
void dfs1(int u, int fa) {
    for (int i = 0; i < son[u].size(); i++) {
        int v = son[u][i];
        if (v == fa)
            continue;
        int w = xval[u][i];
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
        if (v == fa)
            continue;

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
            int gcd = __gcd(xx, yy);
            xx /= gcd, yy /= gcd;
            son[x].push_back(y);
            xval[x].push_back(yy);
            yval[x].push_back(xx);
            son[y].push_back(x);
            xval[y].push_back(xx);
            yval[y].push_back(yy);
                }
        dfs1(1, 0);
        ll w = 1;

        for (int i = 2; i <= n; i++) {
            w = w * power(i, g[i]) % mod;
        }
        dfs2(1, 0, w);
        printf("%lld\n", ans);
    }
    return 0;
}
