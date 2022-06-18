#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution {
   public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        while (j < s.size() && i < g.size()) {
            if (s[j] >= g[i]) {
                ans++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return ans;
    }
};