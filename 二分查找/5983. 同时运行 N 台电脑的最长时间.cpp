// 2022-1-16周赛第四题
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    // 这题的关键在于没有分析清楚每个电池的供电时间, 即核心在于min(t, v);// 这个
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l = 1, r = 1e16;  // 注意哈, long long的右边界, 10 ^ 16次方;
        long long sum = 0;

        auto check = [&](long long t) -> bool {
            // 关键在于总供电时间
            long long sum = 0;
            for (auto&& v : batteries) {
                sum += min(t, (long long)v);
            }
            if (sum / n >= t)
                return true;
            return false;
        };
        long long ans = 1;
        // 关键弄清楚要求的是什么，最大的符合的
        // 注意二分哦
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};