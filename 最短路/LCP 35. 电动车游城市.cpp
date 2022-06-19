#include <queue>
#include <tuple>
#include <vector>
using namespace std;
class Solution {
   public:
    int electricCarPlan(vector<vector<int>>& paths,
                        int cnt,
                        int start,
                        int end,
                        vector<int>& charge) {
        int n = charge.size();
        const int inf = INT_MAX / 2;
        vector<vector<int>> g(cnt + 1, vector<int>(n + 1, inf));
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto&& e : paths) {
            int i = e[0], j = e[1], v = e[2];
            adj[i].emplace_back(j, v);
            adj[j].emplace_back(i, v);
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            q;
        g[0][start] = 0;

        q.emplace(0, start, 0);
        while (!q.empty()) {
            auto [v, cur, c] = q.top();
            q.pop();
            if (g[c][cur] < v)
                continue;

            if (cur == end) {
                return v;
            }
            if (c < cnt) {
                if (v + charge[cur] < g[c + 1][cur]) {
                    g[c + 1][cur] = v + charge[cur];
                    q.emplace(g[c + 1][cur], cur, c + 1);
                }
            }
            for (auto [to, cost] : adj[cur]) {
                if (c >= cost && g[c][cur] + cost < g[c - cost][to]) {
                    g[c - cost][to] = g[c][cur] + cost;
                    q.emplace(g[c - cost][to], to, c - cost);
                }
            }
        }
        return -1;
    }
};