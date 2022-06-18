#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    long long numberOfWeeks(vector<int>& milestones) {
        int n = milestones.size();
        int ma = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            ma = max(ma, milestones[i]);
            sum += milestones[i];
        }
        sum -= ma;
        if (ma > sum)
            return sum * 2l + 1;
        return sum + ma;
    }
};