#include <iostream>
int dp[200 + 10][200 + 10];
int n, M, T;
int m[200 + 10], t[200 + 10];
using namespace std;

int main()
{
    cin >> n >> M >> T;
    for (int i = 1; i <= n; i++)
    {
        cin >> m[i] >> t[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = M; j >= m[i]; j--)
            for (int k = T; k >= t[i]; k--)
            {
                dp[j][k] = max(dp[j][k], dp[j - m[i]][k - t[i]] + 1);
            }
    }
    cout << dp[M][T];
    return 0;
}