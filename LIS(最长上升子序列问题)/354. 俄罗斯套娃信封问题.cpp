#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),
             [&](const vector<int>& i, const vector<int>& j) {
                 if (i[0] == j[0])
                     return i[1] > j[1];
                 return i[0] < j[0];
             });
        int n = envelopes.size();
        vector<int> f;
        f.push_back(envelopes[0][1]);
        for (int i = 1; i < envelopes.size(); i++) {
            // 找第一个lower_bound, 第一个>= 的
            int num = envelopes[i][1];
            // lower_bound(begin_iter, end_iter, num)
            auto it = lower_bound(f.begin(), f.end(), num);  // 第一个>=
            if (it == f.end()) {
                f.push_back(num);
            } else {
                *it = num;
            }
        }
        return f.size();
        // 终于明白这个题是如何把二维转化为一维的LIS了
        // 其实关键在于由于第一维相同时, 第二维已经是倒序了,
        // 所以他选出来的最长子序列不可能有两个及以上的第一维相同的元素;
    }
};