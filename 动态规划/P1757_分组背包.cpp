#include <iostream>
using namespace std;
// 得考虑清楚怎么存
int n, m;
int si[1000 + 10];           // 记录长度
int a[1000 + 10][1000 + 10]; // 记录索引
int w[1000 + 10], v[1000 + 10];
int dp[1000 + 10];
int main()
{
    cin >> m >> n;
    int tot = 0;
    int g;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i] >> g;
        si[g]++;
        a[g][++si[g]] = i; // 记录
        tot = max(tot, g);
    }
    for (int i = 1; i <= tot; i++)
    {
        // tot 个组
        for (int j = m; j >= 0; j--)
        {
            for (int k = 1; k <= si[i]; k++)
            {
                int id = a[i][k];
                if (j >= w[id])
                {
                    dp[j] = max(dp[j], dp[j - w[id]] + v[id]);
                }
            }
        }
    }
    cout << dp[m];
    return 0;
}