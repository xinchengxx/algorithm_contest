#include <iostream>
using namespace std;
int n, m, ans, dp[(1 << 10)][(1 << 10)][3], a[105], Sum[(1 << 10)];
char x;
int getsum(int S)
{
    int cnt = 0;
    while (S)
    {
        cnt += S & 1;
        S >>= 1;
    }
    return cnt;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            a[i] <<= 1;
            if (x == 'H')
                a[i] += 1;
        }

    for (int i = 0; i < (1 << m); i++)
        Sum[i] = getsum(i);
    // 第一个表示上一行,L = last , S = cur
    for (int S = 0; S < (1 << m); S++)
        if (!(S & a[0] || (S & (S << 1)) || (S & (S << 2))))
            dp[0][S][0] = Sum[S];
    for (int L = 0; L < (1 << m); L++)
        for (int S = 0; S < (1 << m); S++)
        {
            // 注意括号
            if (!(S & a[1] || (S & (S << 1)) || (S & (S << 2)) || (S & L) || (L & a[0]) || (L & (L << 1)) || (L & (L << 2))))
                dp[L][S][1] = Sum[S] + Sum[L];
        }
    for (int i = 2; i < n; i++)
        for (int L = 0; L < (1 << m); L++)
        {
            if (L & a[i - 1] || (L & (L << 1)) || (L & (L << 2)))
                continue;
            for (int S = 0; S < (1 << m); S++)
            {
                if (S & a[i] || L & S || (S & (S << 1)) || (S & (S << 2)))
                    continue;
                for (int FL = 0; FL < (1 << m); FL++)
                {
                    if (FL & L || FL & S || FL & a[i - 2] || (FL & (FL << 1)) || (FL & (FL << 2)))
                        continue;
                    dp[L][S][i % 3] = max(dp[L][S][i % 3], dp[FL][L][(i - 1) % 3] + Sum[S]);
                }
            }
        }
    for (int L = 0; L < (1 << m); L++)
        for (int S = 0; S < (1 << m); S++)
            ans = max(ans, dp[L][S][(n - 1) % 3]);
    cout << ans;
    return 0;
}