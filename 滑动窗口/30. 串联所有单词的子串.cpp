#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.size() == 0)
            return vector<int>();
        int n = words[0].size();
        int w = n * words.size();
        int i = 0;
        unordered_map<string, int> ma, mb;
        for (auto&& e : words)
            ma[e]++;
        vector<int> ans;
        for (int i = 0; i + w <= s.size(); i += 1) {
            int j = i;
            for (j; j < s.size(); j += n) {
                string tmp = s.substr(j, n);
                if (ma[tmp] == 0)
                    break;
                mb[tmp]++;
                if (mb[tmp] > ma[tmp])
                    break;
            }
            if (j == i + w) {
                ans.push_back(i);
            }
            mb.clear();
        }
        return ans;
    }
};