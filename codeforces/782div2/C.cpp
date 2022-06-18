#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<i64> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + arr[i];
    }

    i64 ans = 1e18;

    for (int i = 0; i <= n; i++) {
        i64 tot = 1ll * a * arr[i] +
                  1ll * b * (pre[n] - pre[i] - 1ll * (n - i - 1) * arr[i]);
        ans = min(ans, tot);
    }

    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}