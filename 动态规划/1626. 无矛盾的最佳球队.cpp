
// 感觉就是一个纯粹暴力的dp
// 然后利用排序来增加单调性的方法
// 其实本质在于通过排序来增加单调性，因此可以划归为子问题
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 同质的题目 ===>
class Solution {
   public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        // 好好思考一下
        int n = scores.size();
        vector<int> order(n);
        sort(order.begin(), order.end(), [&](int i, int j) {
            if (ages[i] == ages[j]) {
                return scores[i] < scores[j];
            }
            return ages[i] < ages[j];
        });
        int idx = order[0];
        f[0] = scores[idx];
        int ans = f[0];
        for (int i = 1; i < n; i++) {
            idx = order[i];
            f[i] += scores[i];
            for (int j = 0; j < i; j++) {
                // 要能够选;
                int last = order[j];
                if (scores[last] < scores[idx]) {
                    f[i] = max(f[i], f[j] + scores[idx]);
                }
            }
            ans = max(f[i], ans);
        }
        return ans;
    }
    int f[1005];
};