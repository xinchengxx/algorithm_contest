#include <algorithm>
#include <vector>
using namespace std;
class Solution {
   public:
    int minCost(int maxTime,
                vector<vector<int>>& edges,
                vector<int>& passingFees) {
        //以passingFees的费用的最短路
        //小于maxTime
        // edges表示的一个双向的边
        // f[i][s]到某个城市的最小价值
        int n = passingFees.size();
        const int inf = 1000 * 1001 + 1;
        //得弄清楚状态转移是怎么转移的
        vector<vector<int>> f(1000 + 1, vector<int>(n + 1, inf));
        //考虑一下状态转移方程
        f[0][0] = passingFees[0];
        for (int i = 1; i <= maxTime; i++) {
            for (auto&& e : edges) {
                //表示的是edges[]
                // v是时间
                int s = e[0], t = e[1], v = e[2];
                //每次dp可以怎么更新;
                //要求的是费用最小
                //搞清楚时间
                if (i >= v) {
                    f[i][s] = min(f[i - v][t] + passingFees[s], f[i][s]);
                    f[i][t] = min(f[i - v][s] + passingFees[t], f[i][t]);
                }
            }
        }
        int ans = inf;
        for (int i = 0; i <= maxTime; i++)
            ans = min(ans, f[i][n - 1]);

        return ans == inf ? -1 : ans;
    }
};