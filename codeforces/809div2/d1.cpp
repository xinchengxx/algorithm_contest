#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    // 仔细想想这个题教会了我什么, 他实质上是枚举了min值，相当于增加了条件
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans = max(ans, a[i] / k);
    }  
    // 顺带一题，这个题稍微用到了一些高斯函数的特性 
    for (int i = 1; i <= a[0]; i++) {
        // 接下来枚举;
        int mx = i;
        for (int j = 0; j < n; j++) {
            mx = max(mx, a[j] / min(k, a[j] / i));
        }
        ans = min(ans, mx - i);
    }
    cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
