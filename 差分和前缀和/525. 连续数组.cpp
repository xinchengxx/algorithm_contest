#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        // 好一个连续数组,,,, 这个题目的想法我只能说很生草！
        int cur = 0;
        int ans = 0;

        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                cur--;
            else
                cur++;

            if (!m.count(cur))
                m[cur] = i;
            else {
                ans = max(i - m[cur], ans);
            }
        }
        return ans;
    }
};