#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
   public:
    //字串和子序列
    //只需要判断
    int lengthOfLongestSubstring(string s) {
        if (s == "")
            return 0;
        //学习一下这个题目标答的写法
        unordered_set<char> occ;
        int n = s.size();
        int rk = -1, i = 0;
        int ans = 1;
        for (; i < n; i++) {
            if (i) {
                occ.erase(s[i - 1]);
            }
            //不要犯太多低级错误
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                occ.emplace(s[rk + 1]);  // emplace操作明显更快
                rk++;
            }
            ans = max(rk - i + 1, ans);
        }
        return ans;
    }
};