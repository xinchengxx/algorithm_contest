#include <algorithm>
#include <vector>
using namespace std;
class Solution {
   public:
    int minCost(int maxTime,
                vector<vector<int>>& edges,
                vector<int>& passingFees) {
        int n = passingFees.size();
        const int inf = 1000 * 1001 + 1;
        vector<vector<int>> f(1000 + 1, vector<int>(n + 1, inf));
        f[0][0] = passingFees[0];
        for (int i = 1; i <= maxTime; i++) {
            for (auto&& e : edges) {
                int s = e[0], t = e[1], v = e[2];
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