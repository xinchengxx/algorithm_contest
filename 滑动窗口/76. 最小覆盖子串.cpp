#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> ma, mb;

        for (int i = 0; i < t.size(); i++) {
            ma[t[i]]++;
        }
        int l = 0, r = 0;
        int b = -1, len = INT_MAX;
        int n = s.size();
        while (l < n) {
            while (r < n && !check(ma, mb)) {
                mb[s[r]]++;
                r++;
            }
            if (check(ma, mb)) {
                int lenth = r - l;
                if (lenth < len) {
                    b = l;
                    len = lenth;
                }
            }
            mb[s[l]]--;
            l++;
        }

        if (b == -1)
            return "";
        return s.substr(b, len);
    }
    bool check(unordered_map<char, int>& ma, unordered_map<char, int>& mb) {
        for (auto&& [k, v] : ma) {
            if (!mb.count(k) || mb[k] < v)
                return false;
        }
        return true;
    }
};