#include <algorithm>
#include <vector>
using namespace std;
class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        // 也是一个简单的dp问题
        int n = nums.size();
        if (n == 0)
            return 0;
        sort(nums.begin(), nums.end());
        vector<int> ans2;
        ans2.push_back(nums[0]);
        for (int i = 0; i < n; i++) {
            if (ans2.back() != nums[i]) {
                ans2.push_back(nums[i]);
            }
        }
        n = ans2.size();
        int f[100000 + 10][2];
        f[0][1] = 1;
        f[0][0] = 0;
        for (int i = 1; i < n; i++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            if (ans2[i - 1] == ans2[i] - 1) {
                f[i][1] = f[i - 1][1] + 1;
            } else {
                f[i][1] = 1;
            }
        }
        return max(f[n - 1][0], f[n - 1][1]);
    }
};