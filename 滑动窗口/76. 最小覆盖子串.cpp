#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    string minWindow(string s, string t) {
        //最小覆盖子串
        // 先找到符合要求的,然后左指针到第一个不能维护的位置，然后更新开始和长度;
        unordered_map<char, int> ma, mb;
        //考虑一下

        for (int i = 0; i < t.size(); i++) {
            ma[t[i]]++;
        }
        int l = 0, r = 0;
        int b = -1, len = INT_MAX;
        int n = s.size();
        while (l < n) {
            // 考虑指针是怎么移动的
            // 右指针移动到符合条件位置;
            while (r < n && !check(ma, mb)) {
                //添加元素;
                mb[s[r]]++;
                r++;
            }
            if (check(ma, mb)) {
                // r此刻是没+的
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
    // 得稍微计算一下时间复杂度才行,这个check相比10^5次方完全可以忽略不计
    bool check(unordered_map<char, int>& ma, unordered_map<char, int>& mb) {
        for (auto&& [k, v] : ma) {
            if (!mb.count(k) || mb[k] < v)
                return false;
        }
        return true;
    }
};