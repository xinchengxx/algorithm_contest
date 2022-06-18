#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
class Solution {
   public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> g(n + 1);
        const int inf = INT_MAX / 2;
        vector<int> dist(n + 1, inf);
        vector<bool> can(n + 1);
        for (auto&& e : edges) {
            g[e[0]].emplace_back(e[1]);
            g[e[1]].emplace_back(e[0]);
        }
        queue<pair<int, int>> q;
        q.push(make_pair(0, 1));
        while (!q.empty()) {
            auto [cost, vex] = q.front();
            q.pop();
            for (auto&& e : g[vex]) {
                if (cost + 1 < dist[e]) {
                    dist[e] = cost + 1;
                    q.push(make_pair(dist[e], e));
                } else if (dist[e] == dist[vex] ||
                           (can[e] && dist[e] < dist[vex])) {
                    if (!can[vex])
                        q.push(make_pair(cost, vex));
                    can[vex] = true;
                }
            }
        }
        int tot = dist[n];
        if (can[n]) {
            tot += 1;
        } else {
            tot += 2;
        }
        int ans = 0;
        for (int i = 1; i < tot; i++) {
            ans += time;
            if ((ans / change) % 2 == 1) {
                int extra = change - (ans % change);
                ans += extra;
            }
        }
        ans += time;
        return ans;
    }
};