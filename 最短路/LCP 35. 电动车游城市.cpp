#include <queue>
#include <tuple>
#include <vector>
using namespace std;
class Solution {
   public:
    //这个计算的是时间的charge
    //是不是依然可以考虑dp
    //到dp[cnt][i]=最小时间
    int electricCarPlan(vector<vector<int>>& paths,
                        int cnt,
                        int start,
                        int end,
                        vector<int>& charge) {
        int n = charge.size();
        const int inf = INT_MAX / 2;
        //这个题的是dijkstra的变种
        //考虑建这种图的套路
        vector<vector<int>> g(cnt + 1, vector<int>(n + 1, inf));
        // adj
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto&& e : paths) {
            int i = e[0], j = e[1], v = e[2];
            adj[i].emplace_back(j, v);
            adj[j].emplace_back(i, v);
        }
        // tuple
        //默认必须是按value排序
        //可以考虑命名改进一下
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            q;
        g[0][start] = 0;
        //为什么可以这样,
        q.emplace(0, start, 0);
        while (!q.empty()) {
            //表示图不空的情况;
            //排序顺序是什么
            //
            auto [v, cur, c] = q.top();
            q.pop();
            if (g[c][cur] < v)
                continue;  //此时不需要更新
            //接下来考虑
            //解析来考虑更新c+1的
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
                //这个大概是对了
                if (c >= cost && g[c][cur] + cost < g[c - cost][to]) {
                    //此时才需要更新
                    g[c - cost][to] = g[c][cur] + cost;
                    q.emplace(g[c - cost][to], to, c - cost);
                }
            }
        }
        return -1;
    }
};