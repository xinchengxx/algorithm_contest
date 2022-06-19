#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    string res;
    int cur = 0;

    vector<int> times(n);
    int i;
    for (i = 0; i < s.size() - 1; i++) {
        if (cur == k)
            break;
        if (s[i] == '1') {
            if (k % 2 == 1) {
                times[i] = 1;
                // k--;
                // res += '1';
                cur++;
            }
            res += '1';
        } else {
            if (k % 2 == 0) {
                times[i] = 1;
                cur++;
            }
            res += '1';
        }
    }
    times[n - 1] += (k - cur);
    for (; i < s.size(); i++) {
        if (cur % 2 == 1) {
            if (s[i] == '1')
                s[i] = '0';
            else
                s[i] = '1';
        }
        res += s[i];
    }

    cout << res << "\n";
    for (int i = 0; i < n; i++)
        cout << times[i] << " ";
    cout << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}