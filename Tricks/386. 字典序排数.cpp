#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    // 太妙了, 本题的思路关键
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        // 本题也是一个神奇的题... It's a math trick
        // 关键在于求对于任意一个number 下面一个字典序是多少;
        int number = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = number;
            if (number * 10 <= n) {
                number *= 10;
            } else {
                while (number % 10 == 9 || number + 1 > n) {
                    number /= 10;
                }
                number += 1;
            }
        }
        return ans;
    }
};