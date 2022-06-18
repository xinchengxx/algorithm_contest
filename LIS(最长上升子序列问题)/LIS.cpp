#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// longest increasing subsequence Question
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        dp[0] = 1;
        int maxnum = 1;
        int n = nums.size();  //获取长度
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            //注意这个哈,一开始默认是自己一个
            int max_n = 1;
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j])
                    max_n = std::max(dp[j] + 1, max_n);

            dp[i] = max_n;
            maxnum = std::max(maxnum, dp[i]);
        }
        return maxnum;
    }

   private:
    int dp[2600];
};