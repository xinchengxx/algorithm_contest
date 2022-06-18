
// 维护一部分和是xxx的可以用前缀和和哈希表
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        unordered_map<int, vector<int>> m;
        m[0] = vector<int>({1});
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (m.count(sum - k)) {
                ans += m[sum - k].size();
            }
            m[sum].push_back(i);
        }
        return ans;
    }
};