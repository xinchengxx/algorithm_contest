#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Dist {
    int x, y, z;
    Dist(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
    bool operator<(const Dist& d) const { return this->z > d.z; }
};

class Solution {
   public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        priority_queue<Dist> q;
        q.emplace(0, 0, 0);
        vector<int> mark(m * n);
        vector<int> dist(m * n, INT_MAX);
        dist[0] = 0;
        while (!q.empty()) {
            auto [x, y, z] = q.top();
            q.pop();
            if (mark[n * x + y] == 1) {
                continue;
            }
            mark[n * x + y] = 1;
            dist[n * x + y] = z;
            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
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