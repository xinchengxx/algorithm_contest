//注意空指针的指向问题
//以及一些特例的判断问题
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    string longestCommonPrefix(vector<string> strs) {
        if (strs.size() == 0)
            return "";
        else {
            int len = strs[0].size();
            for (int i = 0; i < len; i++) {
                char c = strs[0][i];
                for (int j = 0; j < strs.size(); j++)
                    if (i == strs[j].size() || c != strs[j][i])
                        return strs[0].substr(0, i);  // 0开始的i个 0到i-1
            }
        }
    }
};