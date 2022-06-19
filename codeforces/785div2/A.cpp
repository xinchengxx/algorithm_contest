#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    string s;
    cin >> s;

    if (s.size() == 1) {
        cout << "Bob"
             << " " << s[0] - 'a' + 1 << endl;
        return;
    }

    int mi = INT_MAX, tot = 0;
    for (int i = 0; i < s.size(); i++) {
        tot += s[i] - 'a' + 1;
    }
    if (s.size() % 2 == 0) {
        cout << "Alice"
             << " " << tot << endl;
        return;
    } else {
        cout << "Alice"
             << " " << tot - 2 * min(s[0] - 'a' + 1, s[s.size() - 1] - 'a' + 1)
             << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
