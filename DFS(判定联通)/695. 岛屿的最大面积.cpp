#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int ans = 0;
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    ans = max(ans, process(i, j, grid));
                }
            }
        }
        return ans;
    }
    int process(int i, int j, vector<vector<int>>& g) {
        g[i][j] = 0;
        int ans = 1;
        if (i >= 1 && g[i - 1][j] == 1) {
            ans += process(i - 1, j, g);
        }
        if (i < g.size() - 1 && g[i + 1][j] == 1) {
            ans += process(i + 1, j, g);
        }
        if (j >= 1 && g[i][j - 1] == 1) {
            ans += process(i, j - 1, g);
        }
        if (j < g[0].size() - 1 && g[i][j + 1] == 1) {
            ans += process(i, j + 1, g);
        }
        return ans;
    }

   private:
};