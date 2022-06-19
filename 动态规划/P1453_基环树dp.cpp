#include <iostream>
using namespace std;
#define ll long long
#define MAX 100005
int n;
double k;
int val[MAX];
int head[MAX], nxt[MAX << 1], ti[MAX << 1];
int tot;
ll f[MAX][2];
int fa[MAX];
int find(int u) {
    if (fa[u] == u) {
        return u;
    }
    return fa[u] = find(fa[u]);
}
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
    ti[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}

void dfs(int u, int fa) {
    f[u][1] = val[u];
    f[u][0] = 0;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = ti[i];
        if (v == fa)
            continue;
        dfs(v, u);
        f[u][1] += f[v][0];
        f[u][0] += max(f[v][0], f[v][1]);
    }
}
int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        val[i] = read();
        fa[i] = i;
    }
    int root1, root2;
    for (int i = 1; i <= n; i++) {
        int u = read() + 1, v = read() + 1;
        if (find(u) == find(v)) {
            root1 = u;
            root2 = v;
            continue;
        }
        add(u, v);
        add(v, u);
        fa[find(u)] = find(v);
    }
    scanf("%lf", &k);
    dfs(root1, 0);
    ll v1 = f[root1][0];  // 不选
    dfs(root2, 0);
    v1 = max(v1, f[root2][0]);
    printf("%.1lf", v1 * k);
    return 0;
}