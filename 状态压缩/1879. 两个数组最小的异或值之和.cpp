// 本质是让其中一个数组有序了;
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        // 这个题又是如何状态压缩的
        // 以及学习一下费用流的问题(费用流是什么首先得了解)
        // 感觉这个是像是一个套路;
        int n = nums1.size();
        vector<int> f(1 << n, INT_MAX / 2);
        int ans = INT_MAX / 2;
        f[0] = 0;
        for (int i = 0; i < (1 << n); i++) {
            // __builtin_popcount函数学习一下
            int c = __builtin_popcount(i);
            // nums1的异或;
            // 好好思考一下
            // 有一个点我没有想清楚
            for (int j = 0; j < n; j++) {
                if (i & (1 << j) == 1) {
                    // 把这一位变为0;
                    int s = i ^ (1 << j);  // 1 ==> 0
                    // & ^ | 的优先级
                    f[i] = min(f[i], f[s] + (nums1[c] ^ nums2[j]));
                    ans = min(ans, f[i]);
                }
            }
        }
        return ans;
    }
};