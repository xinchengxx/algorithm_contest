#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int mod = 1e9 + 7;

vector<int> nums;

vector<int> f(40000 + 1);

void solve() {
    int n;
    cin >> n;

    cout << f[n] << "\n";
}

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= 40000; i++) {
        int num = i;
        vector<int> digit;
        while (num) {
            digit.push_back(num % 10);
            num /= 10;
        }
        bool flag = true;
        for (int l = 0, r = digit.size() - 1; l < r; l++, r--) {
            if (digit[l] != digit[r]) {
                flag = false;
            }
        }
        if (flag) {
            nums.push_back(i);
        }
    }

    // 背包dp
    f[0] = 1;
    //
    for (int i = 0; i < nums.size(); i++) {
        for (int j = nums[i]; j <= 40000; j++) {
            f[j] = (f[j] + f[j - nums[i]]) % mod;
        }
    }
    while (t--) {
        solve();
    }

    return 0;
}
