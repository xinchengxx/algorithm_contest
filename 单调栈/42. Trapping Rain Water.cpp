//采用单调栈的方法
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
class Solution {
   public:
    int trap(vector<int>& height) {
        stack<int> stk;  //单调栈;
        //采用逐层获取的方法
        int n = height.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && height[stk.top()] < height[i]) {
                //考虑清除这个<号而不是小于等于号其实都是一样的,不过建议弄成小于号好理解
                int top = stk.top();
                stk.pop();
                if (stk.empty())
                    break;
                int left = stk.top();
                int width = i - left - 1;
                int curh = min(height[left], height[i]) - height[top];
                ans += curh * width;
            }
            stk.push(i);
        }
        return ans;
    }
};