#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int p[300000 + 4];
    int find(int x) {
        if (p[x] == x)
            return x;
        return p[x] = find(p[x]);
    }
    void merge(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y)
            return;
        p[x] = y;
    }
    bool gcdSort(vector<int>& nums) {
        for (int i = 0; i <= 300000; i++)
            p[i] = i;
        for (int num : nums) {
            int k = num;
            for (int i = 2; i <= num / i; i++) {
                bool flag = false;
                while (num % i == 0)
                    flag = true, num /= i;
                if (flag) {
                    merge(k, i);
                }
            }
            if (num > 1)
                merge(k, num);
        }
        vector<int> tmp(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == tmp[i])
                continue;
            if (find(nums[i]) != find(tmp[i]))
                return false;
        }
        return true;
    }
};