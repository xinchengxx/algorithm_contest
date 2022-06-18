
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        int n = items.size(), q = queries.size();
        vector<int> ans(q);
        vector<int> order(q);
        for (int i = 0; i < q; i++) {
            order[i] = i;
        }
        sort(order.begin(), order.end(),
             [&](int i, int j) { return queries[i] < queries[j]; });
        sort(items.begin(), items.end());
        int ptr = -1, hi = 0;
        for (int i : order) {
            while (ptr + 1 < n && items[ptr + 1][0] <= queries[i]) {
                ptr++;
                hi = max(hi, items[ptr][1]);
            }
            ans[i] = hi;
        }
        return ans;
    }
};