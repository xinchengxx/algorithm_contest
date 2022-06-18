#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int combinationSum4(vector<int>& nums, int target) {
        //组合总数, 本题是一个考虑顺序的组合背包问题, 首先组合背包问题的模板
        //终于想清楚了, 实际上0 - 1背包, 完全背包, 组合背包只是循环的顺序
        int n = nums.size();
        vector<int> f(target + 1);
        f[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (i >= num && f[i - num] < INT_MAX - f[i])
                    f[i] += f[i - num];
            }
        }
        return f[target];
    }
};