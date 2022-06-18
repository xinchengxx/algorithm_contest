#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
class Solution {
   public:
    int maximumInvitations(vector<int>& favorite) {
        // 本题值得学习的点比较多emmmm
        // 首先就是基环树, 其实就是树加了一条边;
        // 像题目这种数据的给法, 必定是一个基环树森林
        // 然后就是关于把题目进行抽象, 可以从样例进行分析
        // 然后必须得敏锐的发现如何计算
        // 接下来就是对于基环树判断环和树枝的方法
        // 这个相当于是套路了, 那就是采用拓扑排序的方法;
        // 以及为了反向遍历，需要采用反图,
        // 简单来说其实本题的关键以及各种处理的方法, 都是根据题意来的
        // 此外还有一个套路, 就是关于拓扑排序后环的入度会变成1
        // 注意还有一些要关注的优化的细节,
        // 那就是其实一个环只需要遍历一次，因此通过修改deg来避免环上点的重复遍历
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
        // lambda表达式还是用这种方式把
        // 这个标准是多新啊
        auto rdfs = [&](int v) -> int {
            // 获取的是链的最大深度;
            int depth = 1;
            for (int w : fg[v]) {
                // 因为滞空了
                if (deg[w] != 0)
                    continue;
                depth = 0;  //因为cpp规范不一致max(depth, rdfs(w) + 1);
            }
            return depth;
        };
        // 接下来开始考虑
        int max_circle_size = 0, sum_chain = 0;
        for (int v = 0; v < n; v++) {
            if (deg[v] <= 0)
                continue;
            // 遇到环,避免重复遍历
            int w = favorite[v];
            int circe_size = 1;
            // 遇到环然后统计环的长度;
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