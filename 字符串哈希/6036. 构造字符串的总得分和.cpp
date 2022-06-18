#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    const int mod = 1e9 + 7;
    int p = 173;
    long long sumScores(string s) {
        int n = s.size();
        vector<long long> f(n + 1), h(n + 1);
        f[0] = 1;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            f[i] = (f[i - 1] * p) % mod;
            h[i] = (h[i - 1] * p + s[i - 1]) % mod;
        }
        for (int i = n - 1; i >= 0; i--) {
            int l = 1, r = n - i;
            int cur = 0;
            while (l <= r) {
                int mid = (l + r) >> 1;
                long long val = (h[i + mid] + mod - h[i] * f[mid] % mod) % mod;
                if (val == h[mid]) {
                    cur = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            ans += cur;
        }
        return ans;
    }
};