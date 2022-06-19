
#include <vector>
using namespace std;
class Solution {
   public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int ans = 0;
        for (int i = 0; i < n; i += 2) {
            int cur = row[i] / 2;
            if (row[i + 1] / 2 != cur) {
                for (int j = i + 2; j < n; j++) {
                    if (row[j] / 2 == cur) {
                        swap(row[j], row[i + 1]);
                        break;
                    }
                }
                ans++;
            }
        }
        return ans;
    }
};