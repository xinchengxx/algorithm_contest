#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    //最短路的Dijkstra
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //邻接表存;
        vector<vector<pair<int, int>>> g(n + 1);
        for (auto&& s : times)
            g[s[0]].push_back(make_pair(s[2], s[1]));
        //,后面有空格
        // for后面有空格
        vector<int> dist(n + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.push(make_pair(0, k));
        for (int i = 1; i <= n; i++)
            dist[i] = INT_MAX;
        // while 后面也有空格
        dist[k] = 0;
        while (!q.empty()) {
            auto [t, v] = q.top();
            q.pop();
            if (t > dist[v])
                continue;
            for (auto [t2, v2] : g[v]) {
                if (t2 + t < dist[v2]) {
                    dist[v2] = t2 + t;
                    q.push(make_pair(dist[v2], v2));
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, dist[i]);
        return ans == INT_MAX ? -1 : ans;
    }
};