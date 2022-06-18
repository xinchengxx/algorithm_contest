#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> nums;
        backTrack(ans, 0, k, n, 1, nums);
        return ans;
    }
    void backTrack(vector<vector<int>>& ans,
                   int d,
                   int k,
                   int n,
                   int start,
                   vector<int>& nums) {
        if (d == k) {
            ans.push_back(nums);
            return;
        }
        for (int i = start; i <= n; i++) {
            nums.push_back(i);
            backTrack(ans, d + 1, k, n, i + 1, nums);
            nums.pop_back();
        }
    }
};