//这是一个并查集的经典题
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
   public:
    int find(int a) {
        if (fa[a] == a)
            return a;
        return fa[a] = find(fa[a]);
    }
    // union可以自己写;
    vector<bool> friendRequests(int n,
                                vector<vector<int>>& restrictions,
                                vector<vector<int>>& requests) {
        for (int i = 0; i < n; i++)
            fa[i] = i;
        vector<unordered_set<int>> rs(n);
        for (auto&& res : restrictions) {
            rs[res[0]].insert(res[1]);
            rs[res[1]].insert(
                res[0]);  // unoreder_set的api 接口 ,也可以传入一系列迭代器
        }
        // 还需要维护pyq
        vector<unordered_set<int>> fri(n);
        vector<bool> ans;
        for (int i = 0; i < n; i++)
            fri[i].insert(i);
        for (auto&& re : requests) {
            int a = find(re[0]), b = find(re[1]);
            //看看能不能交朋友
            bool f = true;
            for (auto&& e : fri[b]) {
                if (rs[a].count(e)) {
                    f = false;
                    break;
                }
            }
            ans.push_back(f);
            if (!f)
                continue;
            // 合并朋友圈和仇人圈
            if (rs[a].size() > rs[b].size())
                swap(a, b);
            rs[a].insert(rs[b].begin(), rs[b].end());
            fri[a].insert(fri[b].begin(), rs[b].end());
            fa[b] = a;
        }
        return ans;
    }

   private:
    int fa[1000 + 10];
};