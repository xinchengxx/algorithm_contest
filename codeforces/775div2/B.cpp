#include <bits/stdc++.h>
using namespace std;
int t, n;

vector<int> a(2e5 + 10);

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        a.clear();
        bool flag = false;
        long long sum = 0;
        int ma = INT_MIN;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
            if (a[i])
                flag = true;
            ma = max(ma, a[i]);
        }
        if (flag == false) {
            cout << 0 << endl;
            continue;
        }
        sum -= ma;
        if (sum >= ma)
            printf("1\n");
        else {
            long long ans = ma - sum;
            printf("%lld\n", ans);
        }
    }
    return 0;
}
