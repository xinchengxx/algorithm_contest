#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int minimumFinishTime(vector<vector<int>>& tires,
                          int changeTime,
                          int numLaps) {
        int n = tires.size();
        vector<int> minTime(18, INT_MAX / 2);
        for (auto&& tire : tires) {
            int fi = tire[0];
            long long time = fi;
            for (int x = 1, sum = 0; time < fi + changeTime; x++) {
                sum += time;
                minTime[x] = min(minTime[x], sum);
                time *= tire[1];
            }
        }
        vector<int> f(numLaps + 1, INT_MAX / 2);
        f[0] = -changeTime;
        for (int i = 1; i <= numLaps; i++) {
            for (int j = 1; j <= min(i, 17); j++) {
                f[i] = min(f[i], f[i - j] + changeTime + minTime[j]);
            }
        }
        return f[numLaps];
        // 好家伙, 它这个是如何想到的呢
        // fi * ri ^ (x - 1) < fi + changeTime
        // 2 ^ (x - 1) < changeTime
        // x <= 17;
        //
    }
};