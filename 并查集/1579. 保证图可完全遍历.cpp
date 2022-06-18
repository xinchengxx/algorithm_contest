// 也是一个好题, 关键在于思想的思考和如何求最小联通子图的问题,
// 有点像求最小生成树
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int find(vector<int>& par, int x) {
        if (par[x] == x)
            return x;
        return par[x] = find(par, par[x]);
    }
    // 这个并查集还是可以考虑有多点东西的???
    void merge(vector<int>& par, int a, int b) {
        int x = find(par, a), y = find(par, b);
        if (x == y)
            return;
        par[x] = y;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // 其实本题的关键点还是蛮多的, 关键点在于连通图其实约等于最小生成树,
        // 关于本题贪心的证明, 其实可以严谨的分析一下 可以考虑多试一试.....
        // 以及就是这个思路分析还是很明确的!!!
        int cnt3 = n;
        int ans = 0;
        vector<int> par1(n + 1, 0);
        for (int i = 1; i <= n; i++)
            par1[i] = i;
        for (auto&& edge : edges) {
            if (edge[0] == 3) {
                // union
                int x = find(par1, edge[1]), y = find(par1, edge[2]);
                if (x == y)
                    continue;
                merge(par1, x, y);
                cnt3--;
                ans++;
            }
        }
        int cnt1 = cnt3, cnt2 = cnt3;
        vector<int> par2(par1.begin(), par1.end());
        for (auto&& edge : edges) {
            if (edge[0] == 1) {
                int x = find(par1, edge[1]), y = find(par1, edge[2]);
                if (x == y)
                    continue;
                merge(par1, x, y);
                cnt1--;
                ans++;
            } else if (edge[0] == 2) {
                int x = find(par2, edge[1]), y = find(par2, edge[2]);
                if (x == y)
                    continue;
                merge(par2, x, y);
                cnt2--;
                ans++;
            }
        }
        if (cnt1 != 1 || cnt2 != 1)
            return -1;
        return edges.size() - ans;
    }
};