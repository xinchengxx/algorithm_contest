#include <iostream>
using namespace std;
int n, m;
// 稍微思考一下这个题是怎么来的;
long long f[10][2000][81]; // 10  * 2000 * 81
int sit[2048], gs[2048];
int cnt = 0;

void init(int sum, int node, int num)
{
    if (node >= n)
    {
        sit[++cnt] = sum;
        gs[cnt] = num;
        return;
    }
    // 选这个
    init(sum, node + 1, num);
    init(sum + (1 << node), node + 2, num + 1);
}

int main()
{
    scanf("%d%d", &n, &m);
    //初始化
    // 到第i 行有k 个的
    init(0, 0, 0);
    for (int i = 1; i <= cnt; i++)
        f[1][sit[i]][gs[i]] = 1; //初始化为1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= cnt; j++)
            for (int k = 1; k <= cnt; k++)
            {
                // j是下面一行的
                if (sit[j] & sit[k])
                    continue;
                if ((sit[j] << 1) & sit[k])
                    continue;
                if ((sit[k] << 1) & sit[j])
                    continue;
                for (int p = m; p >= gs[j]; p--)
                {
                    f[i][sit[j]][p] += f[i - 1][sit[k]][p - gs[j]];
                }
            }
    long long ans = 0;
    for (int i = 1; i <= cnt; i++)
        ans += f[n][sit[i]][m];
    printf("%lld", ans);
    return 0;
}

// 预处理表示
