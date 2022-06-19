#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<int> tot(1 << n);
        for (int i = 0; i < tot.size(); i++) {
            for (int j = 0; j < n; j++) {
                if (i & (1 << j))
                    tot[i] += jobs[j];
            }
        }
        vector<vector<int>> f(k, vector<int>(1 << n, -1));
        for (int i = 0; i < (1 << n); i++)
            f[0][i] = tot[i];
        for (int i = 1; i < k; i++) {
            for (int u = 0; u < (1 << n); u++) {
                //选取子集：
                int minv = INT_MAX;
                for (int s = u; s; s = (s - 1) & u) {
                    int tmp = max(f[i - 1][u - s], tot[s]);
                    minv = min(minv, tmp);
                }
                f[i][u] = minv;
            }
        }
        return f[k - 1][(1 << n) - 1];
    }
};