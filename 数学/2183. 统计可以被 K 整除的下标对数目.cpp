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