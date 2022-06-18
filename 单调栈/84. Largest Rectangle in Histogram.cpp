// 84. Largest Rectangle in Histogram
// hard
#include <stack>
#include <vector>
using namespace std;
class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int a[100000 + 10];
        a[0] = -1;
        for (int i = 0; i < heights.size(); i++)
            a[i + 1] = heights[i];
        a[heights.size() + 1] = -1;
        stack<int> s;
        s.push(0);
        int max_area = a[1];
        for (int i = 1; i <= heights.size() + 1; i++) {
            while (a[s.top()] > a[i]) {
                int num = s.top();
                s.pop();
                int new_top = s.top();
                int area = a[num] * (i - new_top - 1);
                max_area = max(area, max_area);
            }
            s.push(i);
        }

        return max_area;
    }
};