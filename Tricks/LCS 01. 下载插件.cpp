// 这题是一个math trick
#include <iostream>
using namespace std;
class Solution {
   public:
    int leastMinutes(int n) {
        int cnt = 0;
        int base = 1;
        while (base < n) {
            cnt++;
            base *= 2;
        }
        return cnt + 1;
    }
};