#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int lastStoneWeightII(vector<int>& stones) {
        // 主要要记住背包的特性???, 然后要学会转移
        // 向那个组合背包的问题??以及排列的问题
        int n = stones.size();
        // 最后一块石头的重量 || 这个题也算是半个套路题了吧???
        int sum = 0;
        for (int stone : stones)
            sum += stone;
        vector<bool> f(sum / 2 + 1, false);
        // 这是 0-1背包问题, 好一个套路的背包dp题, 关键在于两层循环的遍历
        f[0] = true;
        for (int stone : stones) {
            for (int j = sum / 2; j >= stone; j--) {
                f[j] = f[j] || f[j - stone];
            }
        }
        int ma = INT_MIN;
        for (int i = sum / 2; i >= 0; i--) {
            if (f[i]) {
                ma = i;
                break;
            }
        }
        return abs(sum - 2 * ma);
    }
};
