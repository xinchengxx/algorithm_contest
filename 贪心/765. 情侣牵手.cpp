//要么就是换,要么就是不换,直接把情况罗列出来就好了
//当场换就是最好的
#include <vector>
using namespace std;
class Solution {
   public:
    int minSwapsCouples(vector<int>& row) {
        //直接贪心策略;
        //这个贪心的证明可以考虑一下,注意要弄清楚一个习惯,贪心需要的是证明
        //那个吃药的也是贪心
        int n = row.size();
        int ans = 0;
        for (int i = 0; i < n; i += 2) {
            //每次都+=2
            //然后直接贪心交换;
            int cur = row[i] / 2;
            if (row[i + 1] / 2 != cur) {
                //表示不是情侣需要互换;
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