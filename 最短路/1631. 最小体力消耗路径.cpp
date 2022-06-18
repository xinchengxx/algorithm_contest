#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// 关于本题如何保证Dijkstra算法呢
// 以及priority_queue<> 默认是什么(小根堆)
struct Dist {
    int x, y, z;
    Dist(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
    bool operator<(const Dist& d) const { return this->z > d.z; }
};

// 本题的知识点有点多啊;
// 1. 关于重载运算符
// 2. 关于Dijkstra算法(priority_queue是一个小根堆), 还有何时该标记
// 3. 如何把表格问题抽象为图问题，并且压缩存储
// 4. 关于方向坐标的使用方法
// 5. 关于emplace方法的本质是调用其构造函数

class Solution {
   public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        // 想一想;
        // 这个题是一个好题
        // 首先考虑一下如何把这种gird抽象成graph
        // 首先考虑的代价, 实际上是由两个点唯一确定的，因此由图的明显特征
        int m = heights.size(), n = heights[0].size();
        // 接下来考虑如何使用最短路径;
        priority_queue<Dist> q;
        q.emplace(0, 0, 0);
        // 接下来在考虑一下如何压缩二维数组;
        vector<int> mark(m * n);
        vector<int> dist(m * n, INT_MAX);  // 这个
        dist[0] = 0;
        while (!q.empty()) {
            auto [x, y, z] = q.top();
            q.pop();
            if (mark[n * x + y] == 1) {
                continue;  // 注意这个
            }
            // 什么时候标记呢, 一定是出队的时候标记好;
            mark[n * x + y] = 1;
            dist[n * x + y] = z;
            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                // 一定要保证不出界
                if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                    !mark[n * nx + ny]) {
                    q.emplace(nx, ny,
                              max(z, abs(heights[nx][ny] - heights[x][y])));
                }
            }
        }
        return dist[n * m - 1];
    }
};