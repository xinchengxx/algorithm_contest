#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> bitCounts(int n) {
        vector<int> ans(n + 1);
        ans[0] = 0;
        int highBits = 1;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1) == 0)) {
                highBits = i;
            }
            ans[i] = ans[i - highBits] + 1;
        }
        return ans;
    }
};