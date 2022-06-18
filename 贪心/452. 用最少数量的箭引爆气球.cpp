#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    int findMinArrowShots(vector<vector<int>>& points) {
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