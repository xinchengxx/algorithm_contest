// 好一个trick
#include <iostream>
using namespace std;
class Solution {
   public:
    // 好一个trick
    int divide(int dividend, int divisor) {
        // 一大堆trick题目
        if (dividend == 0)
            return 0;
        if (divisor == 1)
            return dividend;
        if (divisor == -1) {
            if (dividend > INT_MIN)
                return -dividend;
            else
                return INT_MAX;
        }
        int sign = 0;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            sign = 1;
        int a = abs(dividend), b = abs(divisor);
        int ans = dfs(a, b);
        if (sign)
            return -ans;
        return ans;
    }
    int dfs(long long a, long long b) {
        if (a < b)
            return 0;
        int count = 1;
        long long k = b;
        long long last = 1;
        while (1) {
            last = k;
            k = k + k;
            if (k > a)
                break;
            count = count + count;
        }
        return dfs(a - last, b) + count;
    }
};