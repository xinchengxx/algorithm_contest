// 非常经典的问题
// 关于一个LCS转化为LIS的思路
// 首先需要的是target数组各不相同, 这样才能和下标形成映射
// 然后就变成了最长递增子序列
// 使用哈希表作为一个映射的工具
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        // 本题关于LCS和LIS的转化问题
        // 如何求关于它们的最长公共子序列
        vector<int> f;
        unordered_map<int, int> ma;
        int m = target.size(), n = arr.size();
        for (int i = 0; i < m; i++) {
            ma[target[i]] = i;
        }
        // 求最长公共子序列
        // 核心思想在于你需要知道要求就是增长的尽可能的慢一些
        for (int i = 0; i < arr.size(); i++) {
            if (!ma.count(arr[i]))
                continue;
            int id = ma[arr[i]];
            auto it = lower_bound(f.begin(), f.end(), id);
            if (it == f.end()) {
                f.push_back(id);
            } else {
                *it = id;
            }
        }
        return m - f.size();
    }
};