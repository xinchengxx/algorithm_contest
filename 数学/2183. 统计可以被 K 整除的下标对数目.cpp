#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    long long countPairs(vector<int>& nums, int k) {
        long long ans = 0;
        vector<int> divisor;
        // 求所有因子的方法, 简单而又优雅
        for (int i = 1; i * i <= k; i++) {
            if (k % i == 0)
                divisor.push_back(i);
            if (i * i < k)
                divisor.push_back(k / i);
        }
        // divisor
        unordered_map<int, int> cnt;
        // 首先这个题需要想清楚, 对每一个nums[i]来说, 需要考虑nums[j] (j < i)
        // 需要满足什么条件才能与* nums[i]相乘是k的倍数
        // 然后cnt[d]实际上表示的是这个因子的倍数的个数
        // 还需要想清楚它的含义
        for (int i = 0; i < nums.size(); i++) {
            ans += cnt[k / gcd(nums[i], k)];
            for (int v : divisor) {
                if (nums[i] % v == 0) {
                    cnt[v]++;
                }
            }
        }
        return ans;
    }
};