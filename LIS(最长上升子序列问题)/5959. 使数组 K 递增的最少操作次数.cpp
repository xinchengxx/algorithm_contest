// 这是一个非常好非常经典的题
// 首先学会了求最长上升子序列的二分做法, 巧妙的定义了新的状态变量
// 同时了解到了一个贪心，就是转变为单调非减的最佳方法就是总长度减去最长非递减子序列的长度
// 注意到最长上升和最长非递减是有些许差别的
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            vector<int> f;
            int length = 0;
            for (int j = i; j < n; j += k) {
                ++length;
                auto it = upper_bound(f.begin(), f.end(), arr[j]);
                if (it == f.end()) {
                    f.push_back(arr[j]);
                } else {
                    *it = arr[j];
                }
            }
            ans += length - f.size();
        }
        return ans;
    }
};
