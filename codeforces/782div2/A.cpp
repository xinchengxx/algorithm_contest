#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, r, b;
    cin >> n >> r >> b;
    string ans;

    int aver = r / (b + 1);
    int left = r - aver * (b + 1);

    for (int i = 0; i < (b + 1); i++) {
        if (i < left) {
            for (int j = 0; j < aver + 1; j++)
                ans.push_back('R');
        } else {
            for (int j = 0; j < aver; j++)
                ans.push_back('R');
        }
        ans.push_back('B');
    }
    ans.pop_back();
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}