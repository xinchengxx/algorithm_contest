//通过判断状态数
#include <queue>
#include <vector>
using namespace std;
class Solution {
   public:
    //广度优先搜索
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n = nums.size();
        //记录层数
        bool m[1000 + 5];
        memset(m, 0, sizeof(m));  //
        queue<pair<int, int>> q;
        q.push(make_pair(start, 0));
        while (!q.empty()) {
            auto [x, d] = q.front();
            q.pop();
            //每次压入队列的时候判断就好了
            for (int i = 0; i < n; i++) {
                int x1 = x + nums[i], x2 = x - nums[i], x3 = x ^ nums[i];
                if (x1 == goal || x2 == goal || x3 == goal)
                    return d + 1;
                if (x1 >= 0 && x1 <= 1000) {
                    if (!m[x1]) {
                        q.push(make_pair(x1, d + 1));
                        m[x1] = true;
                    }
                }
                if (x2 >= 0 && x2 <= 1000) {
                    if (!m[x2]) {
                        q.push(make_pair(x2, d + 1));
                        m[x2] = true;
                    }
                }
                if (x3 >= 0 && x3 <= 1000) {
                    if (!m[x3]) {
                        q.push(make_pair(x3, d + 1));
                        m[x3] = true;
                    }
                }
            }
        }
        return -1;
    }
};