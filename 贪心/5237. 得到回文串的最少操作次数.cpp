
#include <iostream>
using namespace std;

class Solution {
   public:
    int minMoveToMakePalindrome(string s) {
        int n = s.size(), ans = 0;
        int i = 0, j = n - 1;
        for (i = 0, j = n - 1; i < j; i++) {
            bool flag = false;
            for (int k = j; k >= i; k--) {
                if (s[i] == s[k]) {
                    if (k == i) {
                        flag = true;
                        break;
                    }
                    for (; k < j; k++) {
                        swap(s[k], s[k + 1]);
                        ans++;
                    }
                    break;
                }
            }
            if (flag) {
                ans += n / 2 - i;
            }
        }
        return ans;
    }
};