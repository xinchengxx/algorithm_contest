#include <bits/stdc++.h>
using namespace std;

int t;

void solve() {
    string s;
    char c;
    cin >> s >> c;
    for (int i = 0; i < s.size(); i++) {
        if (i % 2 == 1)
            continue;
        if (s[i] == c) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main() {
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
