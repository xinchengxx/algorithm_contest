#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution {
   public:
    int findUnsortedSubarray(vector<int>& nums) {
        // 本题的三段思路和寻找两个边界的方法可以学习一下;
        int n = nums.size();
        int ma = nums[0], mi = nums[n - 1];
        int l = -1, r = -1;
        for (int i = 1; i < n; i++) {
            if (ma <= nums[i]) {
                ma = nums[i];
            } else {
                r = i;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (mi >= nums[i]) {
                mi = nums[i];
            } else {
                l = i;
            }
        }
        if (l == -1) {
            return 0;
        }
        return r - l + 1;
    }
};