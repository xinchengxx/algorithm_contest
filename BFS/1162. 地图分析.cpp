// 有的时候可以把网格问题转化为图问题,
// 比如本题其实有点像求最短路径的问题....好好思考一下怎么抽象
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
   public:
    // 采用大括号的形式初始化数组dir
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int getDis(int x1, int x2, int y1, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }
    // 这个题如果没有提示bfs真的不一定想的出来
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = -1;
        bool flag = false;
        vector<vector<int>> arr(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    arr[i][j] = 0;
                }
            }
        vector<vector<bool>> mark(n, vector<bool>(n, false));

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 0) {
                    mark[i][j] = true;
                    q.push(make_pair(i, j));
                }
            }
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            // 四个方向;
            for (int i = 0; i < 4; i++) {
                int dx = x + dir[i][0];
                int dy = y + dir[i][1];
                if (dx >= 0 && dx < n && dy >= 0 && dy < n) {
                    if (!mark[dx][dy]) {
                        arr[dx][dy] =
                            arr[x][y] + 1;  // 一定是小的先访问, bfs特性
                        q.push(make_pair(dx, dy));
                        mark[dx][dy] = true;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == INT_MAX / 2)
                    continue;
                ans = max(ans, arr[i][j]);
            }
        if (ans == 0)
            return -1;
        return ans;
    }
};