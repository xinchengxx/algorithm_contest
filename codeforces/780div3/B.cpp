#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if (n == 1) {
            if (a[0] > 1) {
                printf("No\n");
                continue;
            } else {
                printf("Yes\n");
                continue;
            }
        } else {
            if (a[n - 1] - a[n - 2] >= 2) {
                printf("No\n");
                continue;
            } else {
                printf("Yes\n");
                continue;
            }
        }
    }
    return 0;
}
