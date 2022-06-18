#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> xval[100000 + 10];
vector<int> yval[100000 + 10];
int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int color;
            cin >> color;
            xval[color].push_back(i);
            yval[color].push_back(j);
        }
    for (int i = 1; i <= 1e5; i++) {
        sort(xval[i].begin(), xval[i].end());
        sort(yval[i].begin(), yval[i].end());  // mnlog(mn);
    }
    long long ans = 0;
    for (int i = 1; i <= 1e5; i++) {
        int k = xval[i].size();
        for (int t = 0; t < k; t++) {
            ans += (2 * t + 1 - k) * 1LL * xval[i][t];
            ans += (2 * t + 1 - k) * 1LL * yval[i][t];
        }
    }
    printf("%lld", ans);
    return 0;
}
