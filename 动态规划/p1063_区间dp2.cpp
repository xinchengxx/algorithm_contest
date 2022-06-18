#include <iostream>
using namespace std;
int dp[202][202];
int ma, mi;
int h[202], t[202];
int n;
int main() {
    mi = INT_MAX;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        t[i - 1] = h[i];
    }
    t[n] = h[1];
    for (int i = n + 1; i <= 2 * n; i++) {
        h[i] = h[i - n];
        t[i] = t[i - n];
    }

    for (int len = 2; len <= n; len++)
        for (int i = 1; i <= 2 * n; i++) {
            int j = i + len - 1;
            if (j > 2 * n)
                break;
            for (int k = i; k < j; k++) {
                dp[i][j] =
                    max(dp[i][j], dp[i][k] + dp[k + 1][j] + h[i] * t[k] * t[j]);
            }
        }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i][i + n - 1]);
    printf("%d", ans);
    return 0;
}