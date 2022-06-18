#include <iostream>
using namespace std;
const int maxn = 6001;
int head[maxn], to[maxn], ne[maxn];
int tot;
int fa[maxn];
void add(int u, int v) {
    to[++tot] = v;
    ne[tot] = head[u];
    head[u] = tot;
}
int n, dp[maxn][2];
void work(int x) {
    for (int i = head[x]; i; i = ne[i]) {
        work(to[i]);
        dp[x][1] += dp[to[i]][0];
        dp[x][0] += max(dp[to[i]][1], dp[to[i]][0]);
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> dp[i][1];
    }
    int u, v;

    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v;  // v -> u
        fa[u] = v;
        add(v, u);
    }
    int root;
    for (int i = 1; i <= n; i++) {
        if (fa[i] == 0)
            root = i;
    }
    work(root);
    printf("%d", max(dp[root][0], dp[root][1]));
    return 0;
    // 如何在加边的时候就找到根节点;
}