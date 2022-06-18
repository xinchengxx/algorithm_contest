#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for (int stone : stones)
            sum += stone;
        vector<bool> f(sum / 2 + 1, false);
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
