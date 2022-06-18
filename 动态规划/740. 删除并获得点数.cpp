//删除并获得点数
// 关键在于思路的转化
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> ma;
        vector<int> nums2;
        nums2.push_back(nums[0]);
        ma[nums[0]]++;
        for (int i = 1; i < nums.size(); i++) {
            if (nums2.back() != nums[i]) {
                nums2.push_back(nums[i]);
            }
            ma[nums[i]]++;
        }
        int dp[20000 + 10][2];
        dp[0][1] = nums2[0] * ma[nums2[0]];
        dp[0][0] = 0;
        for (int i = 1; i < nums2.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            if (nums2[i - 1] == nums2[i] - 1)
                dp[i][1] = dp[i - 1][0] + nums2[i] * ma[nums2[i]];
            else {
                dp[i][1] =
                    max(dp[i - 1][0], dp[i - 1][1]) + nums2[i] * ma[nums2[i]];
            }
        }
        int n = nums2.size();
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};