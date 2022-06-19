#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> tmp;
        for (int num : nums) {
            tmp[num]++;
        }
        vector<int> cnt;
        for (auto&& [key, value] : tmp) {
            cnt.push_back(value);
        }
        int m = cnt.size(), n = quantity.size();
        vector<int> sum(1 << n);
        for (int i = 0; i < (1 << n); i++) {
            int tot = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    tot += quantity[j];
                }
            }
            sum[i] = tot;
        }
        vector<vector<bool>> dp(m, vector<bool>(1 << n, false));
        // dp[i][j] = true 表示能到cnt[i]为止满足 j;
        for (int i = 0; i < m; i++)
            dp[i][0] = true;
        for (int j = 0; j < (1 << n); j++) {
            if (cnt[0] >= sum[j]) {
                dp[0][j] = true;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < (1 << n); j++) {
                if (i >= 1 && dp[i - 1][j]) {
                    dp[i][j] = true;
                    continue;
                }
                for (int s = j; s; s = (s - 1) & j) {
                    // cnt[i]满足子集;
                    if (cnt[i] >= sum[s] && dp[i - 1][j - s]) {
                        dp[i][j] = true;
                    }
                }
            }
        }
        return dp[m - 1][(1 << n) - 1];
    }
};