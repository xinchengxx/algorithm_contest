#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;
// 细细品味一下本题的贪心思想在哪里
class Solution {
   public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // 我只能说这两个题是完全一样的(指leetcode 435)
        int n = points.size();
        sort(points.begin(), points.end());
        int ans = 1, last = points[0][1];
        for (int i = 1; i < n; i++) {
            if (points[i][0] > last) {
                ans++;
                last = points[i][1];
            } else {
                last = min(points[i][1], last);
            }
        }
        return ans;
    }
};