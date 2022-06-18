// 关于异或值的trick
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int res = 0, mask = 0;
        for (int i = 30; i >= 0; i--) {
            mask = mask | (1 << i);
            int tmp = res | (1 << i);
            unordered_set<int> s;
            for (int j = 0; j < n; j++) {
                int prefix = mask & nums[j];
                if (s.count(prefix ^ tmp)) {
                    res = tmp;
                    break;
                } else {
                    s.insert(prefix);
                }
            }
        }
        return res;
    }
};