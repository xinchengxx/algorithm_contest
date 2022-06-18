#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
class Solution {
   public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> s;
        s.push(num[0]);
        int cnt = 0;
        string ans = "";
        for (int i = 1; i < n; i++) {
            char ch = s.top();
            while (ch > num[i]) {
                if (cnt == k)
                    break;
                s.pop();
                if (s.empty())
                    break;
                ch = s.top();
            }
            s.push(num[i]);
        }
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < k - cnt; i++)
            ans.pop_back();
        int start = 0;
        while (start < ans.size() && ans[start] == '0') {
            start++;
        }
        if (start >= ans.size())
            return "0";
        return ans.substr(start, ans.size() - start);
    }
};