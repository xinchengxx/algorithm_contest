#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int findCheapestPrice(int n,
                          vector<vector<int>>& flights,
                          int src,
                          int dst,
                          int k) {
        const int INF = 101 * 10000 + 1;
        vector<vector<int>> f(n + 1,
                              vector<int>(n, INF));  //可以这样初始化啊,学到了
        f[0][src] = 0;
        for (int i = 1; i <= k + 1; i++) {
            for (auto&& e : flights) {
                int s = e[0], d = e[1], v = e[2];
                f[i][d] = min(f[i - 1][s] + v, f[i][d]);
            }
        }
        int ans = INF;
        for (int i = 0; i <= k + 1; i++) {
            //算了暂时不练这个
            ans = min(ans, f[i][dst]);
        }
        return ans == INF ? -1 : ans;
    }
};
