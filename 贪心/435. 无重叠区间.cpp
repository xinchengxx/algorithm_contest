// 无重叠区间
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //关键是让右边界增长的尽可能的慢
        int ans = 0;
        sort(intervals.begin(), intervals.end());
        int last = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= last) {
                last = intervals[i][1];
                continue;
            } else {
                ans++;
                last = min(last, intervals[i][1]);
            }
        }
        return ans;
    }
};