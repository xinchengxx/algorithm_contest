#include <bits/stdc++.h>

using i64 = long long;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<int>());
    int s = a[0] + 2;
    int mx = m - a[0];

    for (int i = 1; i < n; i++) {
        if (s > mx) {
            cout << "No\n";
            return;
        }
        s += a[i] + 1;
    }
    cout << "Yes\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}