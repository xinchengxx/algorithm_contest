#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    string largestNumber(vector<int>& nums) {
        vector<string> nums2;
        for (int i = 0; i < nums.size(); i++) {
            nums2.push_back(to_string(nums[i]));
        }
        string ans;
        auto cmp = [](string a, string b) -> bool {
            return a + b > b + a ? true : false;
        };
        sort(nums2.begin(), nums2.end(), cmp);
        for (int i = 0; i < nums2.size(); i++) {
            ans += nums2[i];
        }
        if (ans[0] == '0') {
            return "0";
        }
        return ans;
    }
};