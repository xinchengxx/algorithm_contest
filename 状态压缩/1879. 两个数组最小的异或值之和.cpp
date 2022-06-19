
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> f(1 << n, INT_MAX / 2);
        int ans = INT_MAX / 2;
        f[0] = 0;
        for (int i = 0; i < (1 << n); i++) {
            // __builtin_popcount函数学习一下
            int c = __builtin_popcount(i);
            for (int j = 0; j < n; j++) {
                if (i & (1 << j) == 1) {
                    int s = i ^ (1 << j);  // 1 ==> 0
                    f[i] = min(f[i], f[s] + (nums1[c] ^ nums2[j]));
                    ans = min(ans, f[i]);
                }
            }
        }
        return ans;
    }
};