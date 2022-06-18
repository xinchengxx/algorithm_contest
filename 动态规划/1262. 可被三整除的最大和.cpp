#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int maxSumDivThree(vector<int>& nums) {
        //选出能被三整除的???
        // 主要是dp的套路见的过于少了, 由于只有0 1 2 三种状态;
        int n = nums.size();
        vector<vector<int>> f(n, vector<int>(3, 0));
        f[0][1] = INT_MIN, f[0][2] = INT_MIN;
        f[0][0] = 0;  // 关键在于这个初始化, 必须保证一开始不更新
        f[0][nums[0] % 3] = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] % 3 == 1) {
                // 这个数只有加入或者不加入
                f[i][0] = max(f[i - 1][0], f[i - 1][2] + nums[i]);
                f[i][1] = max(f[i - 1][1], f[i - 1][0] + nums[i]);
                f[i][2] = max(f[i - 1][2], f[i - 1][1] + nums[i]);
            } else if (nums[i] % 3 == 2) {
                f[i][0] = max(f[i - 1][0], f[i - 1][1] + nums[i]);
                f[i][1] = max(f[i - 1][1], f[i - 1][2] + nums[i]);
                f[i][2] = max(f[i - 1][2], f[i - 1][0] + nums[i]);
            } else {
                f[i][0] = f[i - 1][0] + nums[i];
                f[i][1] = f[i - 1][1] + nums[i];
                f[i][2] = f[i - 1][2] + nums[i];
            }
        }
        return f[n - 1][0];
    }
};

// 状态压缩降低空间复杂度
class Solution2 {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3);
        for (int num : nums)
            for (int i : vector<int>(dp))
                dp[(i + num) % 3] = max(dp[(i + num) % 3], i + num);
        return dp[0];
    }
};