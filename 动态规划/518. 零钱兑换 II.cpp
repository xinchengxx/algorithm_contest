#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int change(int amount, vector<int>& coins) {
        // 零钱兑换||
        // 本质上背包问题的方案;
        int n = coins.size();
        vector<int> f(amount + 1, 0);
        f[0] = 1;
        for (int coin : coins) {
            for (int j = coin; j <= amount; j++)
                f[j] += f[j - coin];
        }
        return f[amount];
    }
};