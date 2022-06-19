#include <bits/stdc++.h>
using namespace std;
int t;
const int mod = 998244353;
long long f[1000 + 5];

int main() {
    cin >> t;
    f[1] = 1;
    for (int i = 2; i <= 1000; i++) {
        f[i] = f[i - 1] * i;
        f[i] %= mod;
    }
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 == 1)
            printf("0\n");
        else {
            long long ans = f[n / 2] * f[n / 2];
            ans %= mod;
            printf("%lld\n", ans);
        }
    }
    return 0;
}
