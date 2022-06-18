#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int query(int w) {
    cout << "? " << w << std::endl;
    int ans;
    std::cin >> ans;
    return ans;
}

int main() {
    int n;
    cin >> n;
    int l = 1, r = 2000 * 2000;
    while (l < r) {
        int x = (l + r) / 2;
        if (query(x) == 1) {
            r = x;
        } else {
            l = x + 1;
        }
    }
    // 查到单词的和...
    int ans = l;

    for (int i = 1; i <= n; i++) {
        int x = query(l / i);
        if (x != 0) {
            ans = min(ans, l / i * x);
        }
    }
    
    cout << "! " << ans << endl;
    
    return 0;
}