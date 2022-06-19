#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    i64 ans = 1e18;

    for (int i = 0; i < n; i++) {
        i64 res = 0;
        vector<i64> b(n);
        for (int j = i + 1; j < n; j++) {
            i64 t = b[j - 1] / a[j] + 1;
            res += t;
            b[j] = a[j] * t;
        }
        for (int j = i - 1; j >= 0; j--) {
            i64 t = b[j + 1] / a[j] + 1;
            res += t;
            b[j] = a[j] * t;
        }
        ans = min(ans, res);
    }

    cout << ans << endl;
}