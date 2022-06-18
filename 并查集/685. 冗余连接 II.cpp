#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        //并查集的初始化
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }
        vector<int> vec;
        for (int i = 0; i < n; i++) {
            de[edges[i][1]]++;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (de[edges[i][1]] == 2) {
                vec.push_back(i);
            }
        }
        if (vec.size()) {
            //先删掉后者;
            int ne = vec[0];
            for (int i = 0; i < n; i++) {
                //判断有没有环;
                if (i == ne)
                    continue;
                int fr = edges[i][0], to = edges[i][1];
                int s = find(fr), t = find(to);
                if (s == t)
                    return edges[vec[1]];
                fa[s] = t;
            }
            return edges[vec[0]];
        } else {
            for (int i = 0; i < n; i++) {
                int fr = edges[i][0], to = edges[i][1];
                int s = find(fr), t = find(to);
                if (s == t)
                    return edges[i];
                fa[s] = t;
            }
            return vector<int>({0, 0});
        }
    }
    int find(int a) {
        //没有压缩
        if (fa[a] == a)
            return a;
        return fa[a] = find(fa[a]);
    }
    void uni(int a, int b) {
        int s = find(a);
        int t = find(b);
        fa[s] = t;
    }

   private:
    int fa[1000 + 10];
    int de[1000 + 10];
};