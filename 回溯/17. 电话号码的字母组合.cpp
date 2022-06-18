#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits == "")
            return ans;
        unordered_map<char, string> phoneMap{
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        //"" is a rvalue
        string str;
        backtrack(ans, phoneMap, digits, 0, str);
        return ans;
    }
    void backtrack(vector<string>& ans,
                   unordered_map<char, string>& phoneMap,
                   const string& digits,
                   int index,
                   string& strs) {
        if (index == digits.size()) {
            ans.push_back(strs);
            return;
        }
        char nu = digits[index];
        for (const char& c : phoneMap.at(nu)) {
            strs.push_back(c);
            backtrack(ans, phoneMap, digits, index + 1, strs);
            strs.pop_back();
        }
    }
};
