class Solution {
   public:
    int mySqrt(int x) {
        //注意看本题的等号的条件
        //但即使相等但也需要更新条件的时候
        //同时二分查找可以表示一个逼近的过程
        //即可以记录最接近的答案
        int l = 0, r = x;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if ((long long)(mid * mid) <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};