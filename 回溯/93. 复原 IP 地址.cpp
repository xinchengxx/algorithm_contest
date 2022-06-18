#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<string> restoreIpAddress(string s) {
        vector<string> ans;
        string str;
        trackBack(ans, 0, 0, s, str);
        return ans;
    }
    //回溯的一个关键就在于设定回溯递归所使用的参数
    void trackBack(vector<string>& ans,
                   int n,
                   int start,
                   const string& s,
                   string& str) {
        if (n == 4 || start == s.size()) {
            if (n == 4 && start == s.size()) {
                ans.push_back(str.substr(0, str.size() - 1));
            }
            return;
        }
        for (int i = 1; i <= 3; i++) {
            if (i + start > s.size())
                return;
            if (s[start] == '0' && i != 1)
                return;
            if (i == 3 && s.substr(start, i) > "255")
                return;
            string tmp = str;
            str += s.substr(start, i);
            trackBack(ans, n + 1, start + i, s, str);
            str = tmp;
        }
    }
};