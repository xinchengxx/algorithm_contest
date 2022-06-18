#include <bits/stdc++.h>
using namespace std;
int t;

void solve() {
    int n;
    string str;
    cin >> n;
    vector<int> m(n + 1), p(n + 1), f(n + 1);
    int ans = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '-') {
            m[i + 1] = m[i] + 1;
            p[i + 1] = p[i];
            if (i != 0) {
                if (str[i - 1] == '-')
                    f[i] = f[i - 2] + 1;
                else
                    f[i] = f[i - 2];
            }
        } else {
            m[i + 1] = m[i];
            p[i + 1] = p[i] + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // i....j
            int plus = p[j + 1] - p[i];
            int minus = m[j + 1] - m[i];
            if (minus < plus || (minus - plus) % 3 != 0)
                continue;

            int tot = f[j + 1] - f[i];
            cout << tot << " " << (minus - plus) / 3 << endl;
            if (tot >= (minus - plus) / 3) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}