#include <iostream>
int n, m;
using namespace std;
const int maxn = 300 + 5;
int head[maxn], to[maxn], ne[maxn];
int tot;
void add(int u, int v)
{
    to[++tot] = v;
    ne[tot] = head[u];
    head[u] = tot;
}
int f[maxn][maxn];
void work(int fa)
{
    for (int i = head[fa]; i; i = ne[i])
    {
        work(to[i]); // 递归孩子;

        int s = to[i];
        for (int j = m + 1; j >= 1; j--)
        {
            for (int k = 1; k < j; k++)
            {
                f[fa][j] = max(f[fa][j], f[fa][j - k] + f[s][k]);
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int fa, wi;
        scanf("%d%d", &fa, &wi);
        f[i][1] = wi;
        add(fa, i);
    }
    work(0);
    printf("%d", f[0][m + 1]);
    return 0;
}