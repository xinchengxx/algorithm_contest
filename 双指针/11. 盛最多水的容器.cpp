//利用贪心的思想;
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        int i = 0, j = n - 1;
        while (i < j) {
            if (heights[i] < heights[j]) {
                ans = max(ans, heights[i] * (j - i));
                i++;
            } else {
                ans = max(ans, heights[j] * (j - i));
                j--;
            }
        }
        return ans;
    }
};