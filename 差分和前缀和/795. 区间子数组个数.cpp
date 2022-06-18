#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        // 这个atmost的函数, 挺重要的
        // atmostK的求连续区间问题
        int f1 = 0,
            f2 = 0;  // f1指向最大的是 <= left - 1, f2 指向最大的是<= right
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