#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
class Solution {
   public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<vector<int>> fg(n);
        vector<int> deg(n);  // 存入读
        queue<int> q;
        for (int v = 0; v < n; v++) {
            int w = favorite[v];
            deg[w]++;
            fg[w].push_back(v);  // 反图的存储方法;
        }
        for (int v = 0; v < n; v++) {
            if (deg[v] == 0)
                q.push(v);
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            int w = favorite[v];
            deg[w]--;
            if (deg[w] == 0) {
                q.push(w);
            }
        }
        auto rdfs = [&](int v) -> int {
            int depth = 1;
            for (int w : fg[v]) {
                if (deg[w] != 0)
                    continue;
                depth = 0;  //因为cpp规范不一致max(depth, rdfs(w) + 1);
            }
            return depth;
        };

        int max_circle_size = 0, sum_chain = 0;
        for (int v = 0; v < n; v++) {
            if (deg[v] <= 0)
                continue;

            int w = favorite[v];
            int circe_size = 1;

            while (w != v) {
                deg[w] = -1;
                circe_size++;
                w = favorite[w];
            }
            if (circe_size == 2) {
                sum_chain += 0;  //详细见注释rdfs(v) + rdfs(favorite[v]);
            } else {
                max_circle_size = max(max_circle_size, circe_size);
            }
        }
        return max(max_circle_size, sum_chain);
    }
};