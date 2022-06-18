#include <iostream>
#include <vector>
using namespace std;
//排序加剪枝
class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> nums;
        for (int num : candidates) {
            if (freq.empty() || freq.back().first != num) {
                freq.push_back(make_pair(num, 1));
            } else {
                freq.back().second++;
            }
        }
        dfs(ans, 0, target, nums);
    }
    void dfs(vector<vector<int>>& ans, int start, int tar, vector<int>& nums) {
        if (tar == 0) {
            ans.push_back(nums);
            return;
        }
        if (start == freq.size() || freq[start].first > tar) {
            return;
        }
        dfs(ans, start + 1, tar, nums);
        int most = min(freq[start].second, tar / freq[start].first);
        for (int i = 1; i <= most; i++) {
            nums.push_back(freq[start].first);
            dfs(ans, start + 1, tar - freq[start].first * i, nums);
        }
        for (int i = 1; i <= most; i++) {
            nums.pop_back();
        }
    }

   private:
    vector<pair<int, int>> freq;
};