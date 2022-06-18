
// 这个题的经典贪心和原理好好思考一下,
// 其实本质上是把多出的那个奇数元素单独处理了, 不过 先在答案上加上去罢了

// 关于贪心的证明, 可以参考题解的那种思考方式, 先写一个一般性的通式,
// 然后把所有的情况列出来 如果满足某种单调性, 那么它就是最优的

#include <iostream>
using namespace std;

class Solution {
   public:
    // Palindrome, 回文
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