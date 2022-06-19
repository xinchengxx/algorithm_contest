
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 1;

        while (i >= 1 && nums[i - 1] >= nums[i])
            i--;
        int j = i - 1;
        if (i == 0) {
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
