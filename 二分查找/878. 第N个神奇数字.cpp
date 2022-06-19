#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int MOD = 1e9 + 7, lcm = a * b / __gcd(a, b);
        long l = 0, r = (long) 1e15;
        while(l < r) {
            long mid = l + ((r - l) >> 1);
            if (mid / a + mid / b - mid / lcm < n) l = mid + 1;
            else r = mid;
        }
        return (int) (l % MOD);
    }
};