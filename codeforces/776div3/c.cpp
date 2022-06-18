#include <bits/stdc++.h>
using namespace std;

int t;

void solve() {
    int n, m;

    vector<vector<int>> v;

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int xi, wi;
        cin >> xi >> wi;
        v.push_back(vector<int>({wi, xi, i}));
    }
    long long tot = 0;
    vector<pair<int, int>> ans(2 * n);
    sort(v.begin(), v.end(), [&](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
    for (int i = 0; i < 2 * n; i++) {
        ans[i] = {v[i][1], v[i][2]};
        tot += v[i][0];
    }
    cout << tot << "\n";
    sort(ans.begin(), ans.end());
    for (int i = 0, j = 2 * n - 1; i < j; i++, j--) {
        cout << ans[i].second << " " << ans[j].second << "\n";
    }
    cout << "\n";
}

int main() {
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}