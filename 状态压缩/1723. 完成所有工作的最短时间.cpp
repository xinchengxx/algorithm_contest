#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        //状态压缩的套路, 首先第一眼看一下数据范围12, 可能是3亦或者是2进制;
        //对比一下之前两个状态压缩的状态有何不同, 其实本质是一样的
        // 注意哈,
        // 关于子集遍历操作(详情可以见wiki百科的位运算这一节);还得学会判断这个遍历子集的时间复杂度
        // 好题目哈;
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
        // 关于里面两层循环的这个时间复杂度
        // 为什么是3^N 次方
        // 好好思考一下;
        // 因为对于每一个位i, 只有三种情况,
        // 不在集合中，只在小集合中和在大小两个集合中
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