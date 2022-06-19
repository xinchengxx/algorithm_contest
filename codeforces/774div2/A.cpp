#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    i64 k;
    cin >> n >> k;

    cout << k / (1ll * n * n) << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}