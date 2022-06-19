#include <algorithm>
#include <vector>

using namespace std;
class Solution {
   public:
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
        for (int i = 1; i <= freq[start].second; i++) {
            tmp.pop_back();
        }
    }

   private:
    vector<pair<int, int>> freq;
};