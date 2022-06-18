#include <iostream>
#include <queue>
using namespace std;
// 维护前i个的k大元素的变种, 没有好好思考一下, 一定要好好思考的啊
class Solution {
   public:
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size(), n = m / 3;

        // 默认是大根堆哈!!!
        priority_queue<int, vector<int>, greater<int>> minPQ;
        long sum = 0L;
        for (int i = m - n; i < m; ++i) {
            minPQ.push(nums[i]);
            sum += nums[i];
        }
        // 注意看这个题如何维护的i 个里面的k个最大的
        // 为什么我没有想到那个问题呢
        // 先弄好n个进去
        // 然后在动态修改
        vector<long> sufMax(m - n + 1);
        sufMax[m - n] = sum;
        for (int i = m - n - 1; i >= n; --i) {
            minPQ.push(nums[i]);
            sum += nums[i] - minPQ.top();
            minPQ.pop();
            sufMax[i] = sum;
        }

        priority_queue<int> maxPQ;
        long preMin = 0L;
        for (int i = 0; i < n; ++i) {
            maxPQ.push(nums[i]);
            preMin += nums[i];
        }
        long ans = preMin - sufMax[n];
        for (int i = n; i < m - n; ++i) {
            maxPQ.push(nums[i]);
            preMin += nums[i] - maxPQ.top();
            maxPQ.pop();
            ans = min(ans, preMin - sufMax[i + 1]);
        }
        return ans;
    }
};
