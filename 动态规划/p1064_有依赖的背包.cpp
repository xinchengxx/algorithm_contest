#include <iostream>
using namespace std;
int dp[32000 + 10];
int m, n;
int fw[61][3], fv[61][3], w[61], v[61]; // 如果是附件就跳过
bool is[61];
int tot;
int main()
{
    cin >> n >> m;
    int w1, p, q;
    memset(fw, 0, sizeof(fw));
    memset(fv, 0, sizeof(fv));
    memset(w, 0, sizeof(w));
    memset(v, 0, sizeof(v));
    for (int i = 1; i <= m; i++)
    {
        cin >> w1 >> p >> q;
        if (q == 0)
        {
            w[i] = w1,
            v[i] = w1 * p;
            is[i] = true;
        }
        else
        {
            fw[q][0]++; // 第一维表示个数;
            int n = fw[q][0];
            fw[q][n] = w1;
            fv[q][n] = w1 * p;
            is[i] = false;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (is[i])
        {
            //根据附件数量来选
            for (int j = n; j >= 0; j--)
            {
                if (j >= w[i])
                    dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
                if (j >= w[i] + fw[i][1])
                    dp[j] = max(dp[j], dp[j - w[i] - fw[i][1]] + v[i] + fv[i][1]);
                if (j >= w[i] + fw[i][2])
                    dp[j] = max(dp[j], dp[j - w[i] - fw[i][2]] + v[i] + fv[i][2]);
                if (j >= w[i] + fw[i][1] + fw[i][2])
                    dp[j] = max(dp[j], dp[j - w[i] - fw[i][1] - fw[i][2]] + v[i] + fv[i][1] + fv[i][2]);
            }
        }
    }
    cout << dp[n];
    return 0;
}