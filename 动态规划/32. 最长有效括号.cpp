// 一个非常有趣的题目;
#include <iostream>
using namespace std;
class Solution {
   public:
    int longestValidParentheses(string s) {
        dp[0] = 0;
        dp[1] = 0;
        int ans = 0;
        for (int i = 1; i < s.size(); i++) {
            int j = i + 1;
            if (s[i] == '(')
                dp[j] = 0;
            else {
                if (s[i - 1] == '(') {
                    dp[j] = dp[j - 2] + 2;
                } else {
                    // "))"
                    // " )())" // dp[2] = 2, 2 - 2 = 0;
                    int id = j - 1 - dp[j - 1];
                    if (id == 0 || s[id - 1] == ')') {
                        dp[j] = 0;
                    } else {
                        dp[j] = dp[j - 1] + dp[id - 1] + 2;
                    }
                }
            }
        }
        for (int i = 1; i <= s.size(); i++)
            ans = max(ans, dp[i]);
        return ans;
    }
    int dp[30000 + 10];
};