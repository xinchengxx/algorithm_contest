#include <iostream>
#include <cstdio>
using namespace std;
int m, n;
int w[3500], d[3500];
int dp[13000];
const int maxn = 12880;
int main()
{
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> d[i];
    for (int i = 1; i <= n; i++)
        for (int j = maxn; j >= w[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + d[i]);
        }
    printf("%d\n", dp[m]);
    return 0;
}