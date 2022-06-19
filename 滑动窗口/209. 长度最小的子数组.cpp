#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
using namespace std;
class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int l, r = 0;
        int ans = nums[0];
        int mina = INT_MAX;
        //维护l到r 的和
        for (int i = 0; i < n; i++) {
            l = i;
            while (ans < target) {
                r++;
                if (r >= n) {
                    return mina == INT_MAX ? 0 : mina;
                }
                ans += nums[r];
            }
            mina = min(mina, r - l + 1);
            ans -= nums[i];
        }
        return mina == INT_MAX ? 0 : mina;
    }
};