#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    const int mod = 1e9 + 7;
    int numRollsToTarget(int n, int k, int target) {
        // 这个就是分组背包问题, 每组只能选择一个???
        vector<vector<int>> f(n, vector<int>(target + 1));
        // 初始化之后再说
        // 好好思考一下????
        // 实际上是对每一组做一个背包问题, 但是每一组的容量只有一个???

        // 如果想象不出该如何循环的话, 可以考虑列表达式
        // f[i][j] = f[i - 1][j - 1]
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