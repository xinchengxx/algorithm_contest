#include <stdio.h>
#include <vector>

using namespace std;
class Solution {
   public:
    //长度最小的子数组
    //可以双指针
    //从一开始
    //指针一定只能往右移动
    //这是关键
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int l, r = 0;
        int ans = nums[0];
        int mina = INT_MAX;
        //维护l到r 的和
        for (int i = 0; i < n; i++) {
            l = i;
            while (ans < target) {
                r++;
                if (r >= n) {
                    return mina == INT_MAX ? 0 : mina;
                    //返回min
                }
                ans += nums[r];
            }
            mina = min(mina, r - l + 1);
            ans -= nums[i];
        }
        return mina == INT_MAX ? 0 : mina;
        //可以采用前缀和加二分的方法
        //关键在于这个思想,从某个数开始的连续数组
        //即nums[i]....nums[j]可以写成prefix[j]-prefix[i];
        //那么通过二分查找到>=prefix[i]的那个数就行了
        //时间复杂度为O(NlogN)
    }
};