#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        //好好思考一下, 分割等和自己, 判断sum / 2;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];

        if (sum % 2 == 1)
            return false;
        vector<bool> f(sum / 2 + 1, false);
        f[0] = true;
        for (int num : nums) {
            for (int j = (sum / 2); j >= num; j--) {
                f[j] = f[j] || f[j - num];
            }
        }
        return f[sum / 2];
    }
};