#include <bits/stdc++.h>
using namespace std;

int t;

void solve() {
    int l, r;
    cin >> l >> r;
    vector<int> cnt1(32), cnt0(32);
    for (int i = 0; i <= (r - l); i++) {
        int val;
        cin >> val;
        for (int j = 0; j < 32; j++) {
            if (val & 1) {
                cnt1[j]++;
            } else {
                cnt0[j]++;
            }
            val >>= 1;
        }
    }
    int num = 0;
    for (int i = 0; i < 32; i++) {
        if (cnt1[i] > cnt0[i]) {
            num = num ^ (1 << i);
        }
    }
    cout << num << "\n";
}

int main() {
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
