#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for (int i = 0; i < n; i++)
            fa[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j]) {
                    int s = find(i), t = find(j);
                    fa[s] = t;
                }
            }
        }
        unordered_map<int, int> ma;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int s = find(i);
            //每次先查找完那么一定全都压缩完了
            if (!ma.count(s)) {
                ma[s] = 1;
                ans++;
            }
        }
        return ans;
    }
    int find(int a) {
        if (fa[a] == a)
            return a;
        return fa[a] = find(fa[a]);
    }

   private:
    int fa[201];
};