#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
#define MAX 1000005
int n;
int val[MAX];
int head[MAX], nxt[MAX << 1], ti[MAX << 1];
int tot;
int x1, x2, e;
ll f[MAX][2];
int vis[MAX];
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
inline void add(int u, int v) {
    ti[tot] = v;
    nxt[tot] = head[u];
    head[u] = tot++;
}
// 0 表示不选
// -1取反表示为0
void find_circle(int u, int fa) {
    vis[u] = true;
    for (int i = head[u]; ~i; i = nxt[i]) {
        int v = ti[i];
        if (v == fa)
            continue;
        if (vis[v]) {
            x1 = u, x2 = v;
            e = i;
            return;
        }
        find_circle(v, u);  //
    }
}
void dfs(int u, int fa) {
    f[u][1] = val[u];
    f[u][0] = 0;
    vis[u] = true;
    for (int i = head[u]; ~i; i = nxt[i]) {
        int v = ti[i];
        if (v == fa || i == e || (i ^ 1) == e)
            continue;
        dfs(v, u);
        f[u][1] += f[v][0];
        f[u][0] += max(f[v][0], f[v][1]);
    }
}
int main() {
    n = read();
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= n; i++) {
        int wi = read(), v = read();
        val[i] = wi;
        add(i, v);
        add(v, i);
    }
    ll val = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i])
            continue;
        find_circle(i, 0);
        dfs(x1, 0);
        ll m = f[x1][0];
        dfs(x2, 0);
        val += max(m, f[x2][0]);
    }

    printf("%lld", val);
    return 0;
}