#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int bit1(int i) {
        int cnt = 0;
        while (i) {
            cnt++;
            i >>= 1;
        }
        return cnt;
    }
    int maximumANDSum(vector<int>& nums, int numSlots) {
        vector<int> f(1 << (numSlots * 2));
        int ans = 0, n = nums.size();
        f[0] = 0;
        for (int i = 1; i < f.size(); i++) {
            int c = __builtin_popcount(i);
            if (c > n)
                continue;
            for (int j = 0; j < numSlots * 2; j++) {
                if (i & (1 << j)) {
                    int s = i ^ (1 << j);
                    f[i] = max(f[i], f[s] + ((j / 2 + 1) & nums[c - 1]));
                    if (c == n) {
                        ans = max(ans, f[i]);
                    }
                }
            }
        }
        return ans;
    }
};