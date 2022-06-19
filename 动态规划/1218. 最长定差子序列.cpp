// 实际上是一个序列dp
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    // Longest Arithmetic Subsequence
    // dp加入状态是一种常规的操作
    int longestSubsequence(vector<int>& arr, int difference) {
        int f[500000][2];
        unordered_map<int, int> ma;
        f[0][0] = 0;
        f[0][1] = 1;
        ma[arr[0]] = 0;
        for (int i = 1; i < arr.size(); i++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            int la = arr[i] - difference;
            if (!ma.count(la)) {
                f[i][1] = 1;
            } else {
                f[i][1] = f[ma[la]][1] + 1;
            }
            ma[arr[i]] = i;
        }
        return max(f[arr.size() - 1][0], f[arr.size() - 1][1]);
    }
};