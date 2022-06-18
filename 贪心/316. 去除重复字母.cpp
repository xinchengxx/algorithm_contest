#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;
// 本题的反思点, stack是没有find函数的
// 然后关于这个必须保留一个的操作
// 根据基本的贪心思想需要稍微修改一下
class Solution {
   public:
    string removeDuplicateLetters(string s) {
        // 关于贪心的正确性
        // 首先关于结论的正确性
        // 其实原题是关于到某个字母的局部最大的值;
        // 然后如果可以删就删掉，不可以删就不删;
        string ans = "";
        stack<char> st;
        unordered_map<char, int> ma;
        unordered_map<char, bool> mb;
        for (int i = 0; i < s.size(); i++) {
            ma[s[i]]++;
        }
        st.push(s[0]);
        mb[s[0]] = true;
        for (int i = 1; i < s.size(); i++) {
            if (!st.empty()) {
                if (mb[s[i]]) {
                    ma[s[i]]--;
                    continue;
                }
                char ch = st.top();
                while (ma[ch] > 1 && ch > s[i]) {
                    ma[ch]--;
                    st.pop();
                    mb[ch] = false;
                    if (st.empty())
                        break;
                    ch = st.top();
                }
                st.push(s[i]);
                mb[s[i]] = true;
            }
        }
        // 这个逻辑判断哪里出了问题呢;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        string ans2;
        for (int i = 0; i < ans.size(); i++) {
            if (ma[ans[i]] > 1) {
                ma[ans[i]]--;
                continue;
            }
            ans2 += ans[i];
        }

        reverse(ans2.begin(), ans2.end());
        return ans2;
    }
};