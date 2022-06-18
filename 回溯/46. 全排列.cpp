#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    // 全排列
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        trackBack(ans, 0, nums, temp);
        return ans;
    }
    void trackBack(vector<vector<int>>& ans,
                   int d,
                   vector<int>& nums,
                   vector<int>& tmp) {
        if (d == nums.size()) {
            ans.push_back(tmp);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!visit[i]) {
                visit[i] = true;
                tmp.push_back(nums[i]);
                trackBack(ans, d + 1, nums, tmp);
                tmp.pop_back();
                visit[i] = false;
            }
        }
    }

   private:
    bool visit[10];
};