#include <iostream>
using namespace std;
int n, q;
#define MAX 103
int f[MAX][MAX];
int siz[MAX];  // size数组,树上dp常用的数组
int head[MAX], t[MAX << 1], w[MAX << 1], ne[MAX << 1];
int tot;
inline int read() {
    int x = 0;
    bool t = false;
    char ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '-')
        ch = getchar();
    if (ch == '-')
        t = true;
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return t ? -x : x;
}
void add(int u, int v, int wi) {
    t[++tot] = v;
    w[tot] = wi;
    ne[tot] = head[u];
    head[u] = tot;
}
void dp(int u, int fa) {
    // 考虑状态转移方程

    for (int i = head[u]; i; i = ne[i]) {
        int v = t[i];
        if (v == fa)
            continue;
        dp(v, u);
        // 注意此处是子树的边的个数
        // 注意此题统计的是边,不同的siz数组含义是不一样的
        siz[u] += siz[v] + 1;
        // 与初始化为1是有区别的,当中有一个细节就是点是边加1
        // 至少得有子树才行; 考虑时间复杂度是上界肯定是nk^2
        for (int j = min(siz[u], q); j; j--)
            for (int k = 0; k <= min(siz[v], j - 1); k++) {
                f[u][j] = max(f[u][j], f[u][j - k - 1] + f[v][k] +
                                           w[i]);  // 表示这条边的权重;
            }
    }
}

int main() {
    n = read();
    q = read();

    for (int i = 1; i <= n - 1; i++) {
        int u = read(), v = read(), wi = read();
        add(u, v, wi);
        add(v, u, wi);
    }
    dp(1, -1);
    printf("%d", f[1][q]);  // 保留的;
    return 0;
}
