#include <algorithm>
#include <vector>
using namespace std;
class Solution {
   public:
    // 关键在于思路的转化;
    // 在于每个房子最少需要多少的距离;
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        for (int h : houses) {
            int j = upper_bound(heaters.begin(), heaters.end(), h) -
                    heaters.begin();
            int i =
                j - 1;  // heaters.end() - heaters.begin() == heaters.size();
            int Right = j == heaters.size() ? INT_MAX : heaters[j] - h;
            int Left = i == -1 ? INT_MAX : h - heaters[i];
            ans = max(ans, min(Right, Left));
        }
        return ans;
    }
};