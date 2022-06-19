#include <iostream>
using namespace std;
#define ll long long
#define MAX 100005
int n;
int val[MAX];  // 牛的数量;
ll head[MAX], wi[MAX << 1], nxt[MAX << 1], ti[MAX << 1];
int tot;
ll num;
ll nums[MAX], f[MAX], pr[MAX];
inline ll read() {
    ll x = 0;
    bool f = false;
    char ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '-')
        ch = getchar();
    if (ch == '-')
        f = true, ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
inline void add(int u, int v, int w) {
    ti[++tot] = v;
    wi[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot;
}
void dfs1(int u, int fa) {
    nums[u] = val[u];
    for (int i = head[u]; i; i = nxt[i]) {
        int v = ti[i];
        if (v == fa)
            continue;
        dfs1(v, u);
        nums[u] += nums[v];                // 加上孩子的
        pr[u] += pr[v] + nums[v] * wi[i];  // 这一样是+=
    }
}

void dfs2(int u, int fa) {
    for (int i = head[u]; i; i = nxt[i]) {
        int v = ti[i];
        if (v == fa)
            continue;
        f[v] = f[u] - nums[v] * wi[i] + (num - nums[v]) * wi[i];
        dfs2(v, u);
    }
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        val[i] = read();
        num += val[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        int u = read(), v = read(), w = read();
        add(u, v, w);
        add(v, u, w);
    }
    dfs1(1, 0);
    f[1] = pr[1];
    dfs2(1, 0);
    ll ans = 1000000000000000000;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, f[i]);
    }
    printf("%lld", ans);
    return 0;
}
