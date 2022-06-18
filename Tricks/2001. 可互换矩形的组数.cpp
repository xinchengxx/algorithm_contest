#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long ans = 0;
        int n = rectangles.size();
        unordered_map<double, int> ma;
        for (int i = 0; i < n; i++) {
            double wi = (double)rectangles[i][0] / rectangles[i][1];
            ans += ma[wi];
            ma[wi]++;
        }
        return ans;
    }
};