
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    // 首先是遍历
    vector<int> smallestMissingValueSubtree(vector<int>& parents,
                                            vector<int>& nums) {
        int n = parents.size();
        vector<int> ans(n, 1);
        int x = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                x = i;
                break;
            }
        }
        if (x == -1)
            return ans;

        vector<vector<int>> son(n);
        for (int i = 0; i < parents.size(); i++) {
            if (parents[i] == -1)
                continue;
            int fa = parents[i];
            son[fa].push_back(i);
        }
        vector<int> marks(n, false);
        vector<int> bucket(1e5 + 5, 0);
        int k = 1;
        while (parents[x] != -1) {
            // dfs(x);
            while (bucket[k] == 1) {
                k++;
            }
            ans[x] = k;
            x = parents[x];
        }
        // dfs(0);
        while (bucket[k] == 1) {
            k++;
        }
        ans[0] = k;
        return ans;
    }
};