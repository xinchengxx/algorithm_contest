#include <iostream>
using namespace std;
#define MAX 100100
#define MOD 1000000007
int n, K;
void add(int& x, int y) {
    x += y;
    if (x >= MOD)
        x -= MOD;
}
inline int read() {
    int x = 0;
    bool t = false;
    char ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '-')
        ch = getchar();
    if (ch == '-')
        t = true, ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return t ? -x : x;
}
int ne[MAX << 1], head[MAX], t[MAX << 1];
int tot;
inline void Add(int u, int v) {
    t[++tot] = v, ne[tot] = head[u], head[u] = tot;
}
// 注意以下几个是树上dp的经典套路;
int f[MAX][101][2][2], siz[MAX];
int tmp[101][2][2];

void dp(int u, int fa) {
    siz[u] = 1;
    f[u][0][0][0] = 1;
    f[u][1][1][0] = 1;
    for (int i = head[u]; i; i = ne[i]) {
        int v = t[i];
        if (v == fa)
            continue;
        dp(v, u);
        for (int j = 0; j <= siz[u] && j <= K; j++)
            for (int k = 0; k <= siz[v] && k + j <= K; k++) {
                if (f[u][j][0][0]) {
                    add(tmp[j + k][0][0],
                        1ll * f[u][j][0][0] * f[v][k][0][1] % MOD);
                    add(tmp[j + k][0][1],
                        1ll * f[u][j][0][0] * f[v][k][1][1] % MOD);
                }
                if (f[u][j][0][1]) {
                    add(tmp[j + k][0][1], 1ll * f[u][j][0][1] *
                                              (f[v][k][0][1] + f[v][k][1][1]) %
                                              MOD);
                }
                if (f[u][j][1][0]) {
                    add(tmp[j + k][1][0], 1ll * f[u][j][1][0] *
                                              (f[v][k][0][0] + f[v][k][0][1]) %
                                              MOD);
                    add(tmp[j + k][1][1], 1ll * f[u][j][1][0] *
                                              (f[v][k][1][0] + f[v][k][1][1]) %
                                              MOD);
                }
                if (f[u][j][1][1]) {
                    int s = 0;
                    add(s, f[v][k][0][0]);
                    add(s, f[v][k][0][1]);
                    add(s, f[v][k][1][0]);
                    add(s, f[v][k][1][1]);
                    add(tmp[j + k][1][1], 1ll * f[u][j][1][1] * s % MOD);
                }
            }
        siz[u] += siz[v];
        for (int j = 0; j <= siz[u] && j <= K; ++j) {
            f[u][j][0][0] = tmp[j][0][0];
            tmp[j][0][0] = 0;
            f[u][j][0][1] = tmp[j][0][1];
            tmp[j][0][1] = 0;
            f[u][j][1][0] = tmp[j][1][0];
            tmp[j][1][0] = 0;
            f[u][j][1][1] = tmp[j][1][1];
            tmp[j][1][1] = 0;
        }
    }
}

int main() {
    n = read(), K = read();
    for (int i = 1, u, v; i < n; ++i) {
        u = read();
        v = read();
        Add(u, v), Add(v, u);
    }
    dp(1, 0);
    int ans = (f[1][K][0][1] + f[1][K][1][1]) % MOD;
    printf("%d\n", ans);
    return 0;
}