#include <string>

using namespace std;
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        //滑动窗口经典问题,问最大符合某条件的窗口大小,或者窗口的max,min,sum之类的东西;
        int l = 0, r = 0;
        char ma[256] = {0};
        int n = s.size();
        int ans = 0;
        //弄清楚细节才行
        while (r < n) {
            ma[s[r]]++;
            while (ma[s[r]] >= 2) {
                ma[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};