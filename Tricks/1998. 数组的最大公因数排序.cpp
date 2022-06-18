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
        // 这个题算是一个并查集的模板题了, 首先就是关于a与b交换,
        // b与c交换可以任意交换顺序, 推出一个结论,
        // 在一个并查集里面的都可以任意交换顺序
        for (int i = 0; i <= 300000; i++)
            p[i] = i;
        //好好思考一下这个题的本质关键, 如何思考到从质因子开始合并的
        // 这里居然是拷贝复制的, 好像确实是如此, 用: 的int 实际上是拷贝复制的
        // 关键在于这个求质因子的过程, 算是半个套路吧;
        for (int num : nums) {
            int k = num;
            // 这样num最多剩下一个1次的质因子, 这种求质因子的方法, 非常好
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