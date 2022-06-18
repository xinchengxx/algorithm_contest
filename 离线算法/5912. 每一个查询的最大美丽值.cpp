//首先需要考虑这个算法的思路,所谓的queries[i]获取的ans[i],表示是<=
//queries[i]的items[i][1]的最大值 可以考虑按照时间递增排序
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
             //这个[&]不能替换成[]
             // [] 表示不访问外部变量
             // 注意使用 = 不如使用&,可以避免拷贝
             // lambda expression 的作用,形成闭包
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