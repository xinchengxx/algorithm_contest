#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution {
   public:
    string removeDuplicateLetters(string s) {
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