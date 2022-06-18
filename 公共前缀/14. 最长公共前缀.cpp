//注意空指针的指向问题
//以及一些特例的判断问题
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string> strs) {
        const int n = strs.size(), len = strs[0].size();
        if (n == 0)
            return "";
        for (int i = 0; i < len; i++) {
            char c = strs[0][i];
            for (int j = 1; j < n; j++)
                if (i == strs[j].size() || c != strs[j][i])
                    return strs[0].substr(0, i);  // 0开始的i个 0到i-1
        }
        return strs[0].substr(0, len);  // 如果没有返回值，说明前n个字符都相同
    }
};