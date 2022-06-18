#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // 本题的重点在于两个二分查找函数的书写
    // 首先是要弄清楚查找的是什么东西
    // <= 的最大的那个
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {}
    // <= 的最大的
    //  5 5 5 5 5 3
    int bi_s(int val) {
        int l = 1, r = n;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (pos[mid] > val) {
                r = mid - 1;
            } else {
                ans = mid;
                l = mid + 1;
            }
        }
    }

    int bi_s2(int val) {
        int l = 1, r = n;
        int ans = n + 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (pos[mid] < val) {
                l = mid + 1;
            } else {
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }
    // < 最大
    // 5 3
    // 2 3
    // 但这还是有问题啊
    // 比如一次循环退出了怎么办呢
    // < 的最大的
    int bi_s3(int val) {
        int l = 1, r = n;
        int ans = 0;  // 初始化要是0才对
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (pos[mid] >= val) {
                r = mid - 1;
            } else {
                ans = mid;
                l = mid + 1;
            }
        }
        return ans;
    }
    int n;
    int pos[100000 + 5];
    int sum[100000 + 5];
};