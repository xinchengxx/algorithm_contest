#include <vector>
using namespace std;
class Solution {
   public:
    bool canJump(vector<int>& nums) {
        // 记录能跳到的最短距离就好了;
        int n = nums.size();
        int ma = nums[0];

        for (int i = 1; i < n; i++) {
            if (ma < i) {
                return false;
            } else {
                ma = max(ma, i + nums[i]);
            }
        }
        return true;
    }
};