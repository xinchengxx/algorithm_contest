#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int s = 0;

        for (int i = 0; i < nums.size(); i++)
            s += nums[i];
        if ((target + s) % 2 == 1)
            return 0;
        int ntar = (target + s) / 2;
        if (ntar > s || ntar < 0)
            return 0;
        int dp[2000 + 10] = {0};

        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = ntar; j >= nums[i]; j--) {
                dp[j] = dp[j] + dp[j - nums[i]];
            }
        }
        return dp[ntar];
    }
};