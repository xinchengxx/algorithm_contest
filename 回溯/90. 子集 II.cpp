#include <algorithm>
#include <vector>

using namespace std;
class Solution {
   public:
    // 直接排序并且类似那个题一样的,选出target
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int num : nums) {
            if (freq.empty() || freq.back().first != num) {
                freq.push_back(make_pair(num, 1));
            } else {
                freq.back().second++;
            }
        }
        vector<vector<int>> ans;
        vector<int> tmp;
        trackBack(ans, 0, tmp);
        return ans;
    }
    void trackBack(vector<vector<int>>& ans, int start, vector<int>& tmp) {
        if (start == freq.size()) {
            ans.push_back(tmp);
            return;
        }
        // 选0到n个;
        trackBack(ans, start + 1, tmp);
        for (int i = 1; i <= freq[start].second; i++) {
            tmp.push_back(freq[start].first);
            trackBack(ans, start + 1, tmp);
        }
        //回溯到上一层的时候必须恢复这个全局的tmp;
        for (int i = 1; i <= freq[start].second; i++) {
            tmp.pop_back();
        }
    }

   private:
    vector<pair<int, int>> freq;
};