#include <iostream>
#include <vector>
using namespace std;
// 关于处理环形的一种技巧以及关于一些贪心思想的使用
class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < gas.size(); i++) {
            a[i + 1] = gas[i];
            a[i + 1 + n] = gas[i];
            b[i + 1] = cost[i];
            b[i + 1 + n] = cost[i];
        }
        int cnt = 0, start = 1;
        int tank = 0;
        while (start <= n) {
            cnt = 0;
            tank = 0;
            while (cnt < n) {
                tank += (a[start + cnt] - b[start + cnt]);
                if (tank < 0)
                    break;
                cnt++;
            }
            if (cnt == n)
                return start - 1;
            start = start + cnt + 1;
        }
        return -1;
    }
    // ok 知道怎么做了
    int a[100000 * 2 + 2], b[100000 * 2 + 2];
};