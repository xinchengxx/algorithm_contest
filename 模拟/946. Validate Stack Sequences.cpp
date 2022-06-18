//验证栈序列
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
   public:
    bool validStackSequence(vector<int> pushed, vector<int> popped) {
        stack<int> s;  //辅助栈
        int n = pushed.size();
        int ptr = 0;
        for (int i = 0; i < n; i++) {
            int num = popped[i];
            if (!s.empty() && s.top() == popped[i]) {
                s.pop();
                continue;
            }

            while (ptr < n && pushed[ptr] != popped[i]) {
                s.push(pushed[ptr]);
                ptr++;
            }
            if (ptr >= n)
                return false;
            ptr++;
        }
        return true;
    }
};