#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Q {
    int id, pos, len;
    Q(int id, int pos, int len) : id(id), pos(pos), len(len) {}
    bool operator<(const Q& that) { return this->pos < that.pos; }
};

class Solution {
   public:
    vector<int> minInterval(vector<vector<int>>& intervals,
                            vector<int>& queries) {
        int n = queries.size();
        vector<int> ans(n);
        vector<Q> qry;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < n; i++)
            qry.push_back({i, queries[i], 0});

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        sort(qry.begin(), qry.end());
        int m = intervals.size(), tail = 0;
        for (int i = 0; i < n; i++) {
            while (tail < m && intervals[tail][0] <= qry[i].pos) {
                pq.emplace(intervals[tail][1] - intervals[tail][0] + 1,
                           intervals[tail][1]);
                tail++;
            }
            while (!pq.empty()) {
                auto [len, right] = pq.top();
                if (right >= qry[i].pos) {
                    ans[qry[i].id] = len;
                    break;
                }
                pq.pop();
            }
            if (pq.empty()) {
                ans[qry[i].id] = -1;
            }
        }
        return ans;
    }
};