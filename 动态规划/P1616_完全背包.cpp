#include <iostream>
//主要是要理清楚这个优化的思路,从状态转移方程一步一步转变过来的
#include <cstdio>
int t, s;
int a[10000 + 10], v[10000 + 10];
long long dp[10000000 + 10];
using namespace std;

int main() {
    cin >> t >> s;
    for (int i = 1; i <= s; i++) {
        cin >> a[i] >> v[i];
    }
    for (int i = 1; i <= s; i++)
        for (int j = a[i]; j <= t; j++) {
            dp[j] = max(dp[j], dp[j - a[i]] + v[i]);
        }
    cout << dp[t];
    return 0;
}
