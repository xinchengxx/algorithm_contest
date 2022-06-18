#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    bool workBreak(string s, vector<string> wordDict) {}
    bool process(int start,
                 string& s,
                 unordered_map<int, bool>& mem,
                 set<string>& m) {
        if (start == s.size())
            return true;
        //从缓存中查找
        if (mem.count(start))
            return mem[start];
        for (int i = start + 1; i <= s.size(); i++) {
            if (m.count(s.substr(start, i - start)) && process(i, s, mem, m)) {
                mem[start] = true;
                return true;
            }
        }
        mem[start] = false;
        return false;
    }

   private:
    unordered_map<int, bool> mem;  //记忆化数组
    set<string> m;
};