#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
   public:
    //可以一并学习
    //那个最长公共子串的,完全类似
    //好好思考一下dp的核心思想

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        for (int i = 0; i <= m; i++)
            dp[i][0] = i;
        for (int i = 0; i <= n; i++)
            dp[0][i] = i;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = min(min(dp[i - 1][j - 1], dp[i][j - 1] + 1),
                                   dp[i - 1][j] + 1);
                } else {
                    dp[i][j] = min(min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1),
                                   dp[i][j - 1] + 1);
                }
            }
        return dp[m][n];
    }

   private:
    int dp[501][501];
};