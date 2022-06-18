#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    int findSubstringInWraproundString(string p) {
        unordered_map<char, int> m;
        // 确实有点像dp，
        m[p[0]] = 1;
        int n = p.size();
        vector<int> f(n);
        f[0] = 1;
        // 关于这个字串的问题没有比较好的联想到是我的问题........
        // 实际上由于这个包含性是很确定的....
        // 以及关于本题前缀和的变化母题
        for (int i = 1; i < p.size(); i++) {
            if (p[i] - p[i - 1] == 1 || p[i] - p[i - 1] == -25) {
                f[i] = f[i - 1] + 1;
            } else {
                f[i] = 1;
            }
            m[p[i]] = max(m[p[i]], f[i]);
        }
        int ans = 0;
        for (auto&& [k, v] : m)
            ans += v;
        return ans;
    }
};