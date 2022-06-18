#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int f1 = 0, f2 = 0;
        int n1 = 0, n2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= left - 1) {
                n1 = n1 + 1;
                f1 += n1;
            } else {
                n1 = 0;
            }
            if (nums[i] <= right) {
                n2 = n2 + 1;
                f2 += n2;
            } else {
                n2 = 0;
            }
        }
        return f2 - f1;
    }
};