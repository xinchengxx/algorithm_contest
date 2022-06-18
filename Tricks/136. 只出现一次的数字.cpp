// 位运算trick
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int N = nums.size();
        if(N < 2)
            return nums.back();
        int Or = 0;
        for(int i = 0; i < N; i++) {
            Or ^= nums[i]; // 利用异或的性质 a^a=0 和 a^0=a
        }
        return Or; // 最后返回值一定是 singleNumber^0=singleNumber
    }
};