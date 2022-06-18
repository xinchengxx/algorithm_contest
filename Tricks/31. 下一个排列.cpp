// 一个非常有意思的trick
// 这个题的关键思路在于如何让增长的尽可能的慢, 非常有趣的trick
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 1;
        // 本题的等于号可以通过带入数据尝试
        while (i >= 1 && nums[i - 1] >= nums[i])
            i--;
        int j = i - 1;
        if (i == 0) {
            // 表示完全逆序;
            int l = 0, r = n - 1;
            while (l < r) {
                swap(nums[l], nums[r]);
                l++, r--;
            }
            return;
        }
        int k;
        for (k = n - 1; k >= j; k--) {
            if (nums[k] > nums[j])
                break;
        }
        swap(nums[k], nums[j]);
        int l = i, r = n - 1;
        while (l < r) {
            swap(nums[l], nums[r]);
            l++, r--;
        }
    }
};
