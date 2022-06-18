#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> numbers;
        trackBack(ans, candidates, target, numbers, 0);
        return ans;
    }
    void trackBack(vector<vector<int>>& ans,
                   const vector<int>& cand,
                   int target,
                   vector<int>& numbers,
                   int start) {
        if (target == 0) {
            ans.push_back(numbers);
            return;
        }
        // 要思考清除为什么会有重复的情况
        // 可以手动添加一个搜索顺序,同层的搜索是按一定顺序来的
        for (int i = start; i < cand.size(); i++) {
            if (target >= cand[i]) {
                numbers.push_back(cand[i]);
                trackBack(ans, cand, target - cand[i], numbers, i);
                numbers.pop_back();
            }
        }
    }
};