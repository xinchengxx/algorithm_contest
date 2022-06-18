#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int change(int amount, vector<int>& coins) {
        // 零钱兑换||
        // 本质上背包问题的方案;

        // 实际上leetcode上的背包问题可以考虑不用压缩空间,
        // 如果思考不出的话可以考虑列一下表达式
        int n = coins.size();
        vector<int> f(amount + 1, 0);
        f[0] = 1;
        // 这题做复杂了, 实际上还是要考虑一下它的优化
        for (int coin : coins) {
            for (int j = coin; j <= amount; j++)
                f[j] += f[j - coin];
        }
        return f[amount];
    }
};