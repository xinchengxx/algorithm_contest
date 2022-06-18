#include <iostream>
using namespace std;
#define MAX 1000010
// 套路在于先统计一些诸如深度 节点个数之类的东西
// 然后在考虑换根的转移
int n, tot, id;
int head[MAX];
int t[MAX << 1], ne[MAX << 1];
long long ans;
long long f[MAX], d[MAX], siz[MAX];
inline void add(int u, int v) {
    t[++tot] = v;
    ne[tot] = head[u];
    head[u] = tot;
}
void dp1(int u, int fa) {
    //统计深度;
    siz[u] = 1;
    d[u] = d[fa] + 1;
    for (int i = head[u]; i; i = ne[i]) {
        int v = t[i];
        if (v == fa)
            continue;
        dp1(v, u);
        // 表示节点个数
        siz[u] += siz[v];
    }
}
void dp2(int u, int fa) {
    for (int i = head[u]; i; i = ne[i]) {
        int v = t[i];
        if (v == fa)
            continue;
        f[v] = f[u] - siz[v] + n - siz[v];
        dp2(v, u);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v), add(v, u);
    }
    dp1(1, 0);
    for (int i = 1; i <= n; i++)
        f[1] += d[i];
    dp2(1, 0);
    for (int i = 1; i <= n; i++)
        if (ans < f[i])
            ans = f[i], id = i;
    printf("%d", id);
    return 0;
}