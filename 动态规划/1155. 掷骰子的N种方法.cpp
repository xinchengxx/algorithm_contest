#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    const int mod = 1e9 + 7;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> f(n, vector<int>(target + 1));
        for (int i = 1; i <= min(k, target); i++)
            f[0][i] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = target; j >= 1; j--) {
                for (int l = 1; l <= k; l++) {
                    if (l > j)
                        continue;
                    f[i][j] = (f[i][j] + f[i - 1][j - l]) % mod;
                }
            }
        }
        return f[n - 1][target];
    }
};