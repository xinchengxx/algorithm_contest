#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int combinationSum4(vector<int>& nums, int target) {
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