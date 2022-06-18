class Solution {
   public:
    int mySqrt(int x) {
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