#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
   public:
    int minimumJumps(vector<int>& forbbiden, int a, int b, int x) {
        int n = forbbiden.size();
        int ban[6000 + 1];
        memset(ban, 0, sizeof(ban));
        for (int num : forbbiden) {
            ban[num] = 1;
        }
        int dist[6000 + 1][2];
        memset(dist, 0x3f, sizeof(dist));
        dist[0][0] = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        while (!q.empty()) {
            auto [i, pre] = q.front();
            q.pop();
            if (i == x)
                return dist[i][pre];
            //为什么此处不用优先队列;很简单, 因为都+1, bfs的特性就足以保持成立;
            if (ban[i] == 1)
                continue;
            ban[i] = 1;
            if (!pre && i - b >= 0 && !ban[i - b] &&
                dist[i][pre] + 1 < dist[i - b][1]) {
                dist[i - b][1] = dist[i][pre] + 1;
                q.push(make_pair(i - b, 1));
            }
            if (i + a <= 6000 && !ban[i + a] &&
                dist[i][pre] + 1 < dist[i + a][0]) {
                dist[i + a][0] = dist[i][pre] + 1;
                q.push(make_pair(i + a, 0));
            }
        }
        return -1;
    }
};