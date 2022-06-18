#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int first, last;
        int n = intervals.size();
        if (n == 0)
            return vector<vector<int>>();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        first = intervals[0][0], last = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][1] <= last)
                continue;
            else if (intervals[i][0] > last) {
                ans.push_back({first, last});
                first = intervals[i][0];
                last = intervals[i][1];
            } else if (intervals[i][1] > last) {
                last = intervals[i][1];
            }
        }
        ans.push_back({first, last});
        return ans;
    }
};