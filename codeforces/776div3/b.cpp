#include <bits/stdc++.h>
using namespace std;

int t;

void solve() {
    int l, r, a;
    cin >> l >> r >> a;
    if (r < a) {
        cout << r << "\n";
        return;
    }

    int k1 = r / a, b1 = r % a;
    int ans = k1 + b1;

    if ((k1 - 1) * a + a - 1 >= l) {
        ans = max(ans, k1 - 1 + a - 1);
    }
    cout << ans << "\n";
}

int main() {
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}