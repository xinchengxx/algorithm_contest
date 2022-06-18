#include <iostream>
using namespace std;
int dp1[202][202]; //dp 枚举长度,
int dp2[202][202];
int ma, mi;
int a[202];
int n;
int sum[202];
// 首先需要先优先列出转移方程来
int main()
{
    mi = INT_MAX;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = n + 1; i <= 2 * n; i++)
    {
        a[i] = a[i - n];
        sum[i] = sum[i - 1] + a[i];
    }

    //开始枚举长度
    for (int len = 2; len <= n; len++)
    {
        // 这个 2 * n没看懂
        // 注意这个地方是有一个问题的
        // 这个k + 1 是有可能
        // 因为是要用到后面的
        for (int i = 1; i <= 2 * n; i++)
        {
            int j = i + len - 1;
            // 注意这个j
            if (j >= 2 * n)
                continue;
            dp2[i][j] = 99999; //疑惑
            for (int k = i; k < j; k++)
            {
                dp1[i][j] = max(dp1[i][j], dp1[i][k] + dp1[k + 1][j] + sum[j] - sum[i - 1]);
                dp2[i][j] = min(dp2[i][j], dp2[i][k] + dp2[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ma = max(ma, dp1[i][i + n - 1]);
        mi = min(mi, dp2[i][i + n - 1]);
    }
    printf("%d\n%d", mi, ma);
    return 0;
}