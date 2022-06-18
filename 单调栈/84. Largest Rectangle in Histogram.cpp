// 84. Largest Rectangle in Histogram
// hard
#include <stack>
#include <vector>
using namespace std;
class Solution {
   public:
    //弄清楚思路
    //可以通过存下标的方式反向直接访问数组
    //通过加入哨兵的形式
    int largestRectangleArea(vector<int>& heights) {
        //使用哨兵
        //注意使用哨兵的情况
        //该如何使用哨兵
        int a[100000 + 10];
        a[0] = -1;
        for (int i = 0; i < heights.size(); i++)
            a[i + 1] = heights[i];
        a[heights.size() + 1] = -1;
        //拷贝的哨兵上
        stack<int> s;
        s.push(0);
        int max_area = a[1];
        for (int i = 1; i <= heights.size() + 1; i++) {
            //栈一定不会空
            while (a[s.top()] > a[i]) {
                int num = s.top();
                s.pop();  //首先这个可以直接弹出
                int new_top = s.top();
                int area = a[num] * (i - new_top - 1);
                max_area = max(area, max_area);
            }
            s.push(i);
        }

        return max_area;
    }
};