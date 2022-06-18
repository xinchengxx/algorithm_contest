//在本题中添加了一个求取个数的部分
//考虑增加一个dp数组
#include <vector>
using namespace std;
class Solution {
   public:
    //采用这种方法进行dp的话时空复杂度为O(N^2) 空间复杂度为O(N)
    int findNumberOfLIS(vector<int> nums) {
        int n = nums.size();  //获取长度
        dp[0] = 1;
        int max_num = 1;
        for (int i = 1; i < n; i++) {
            nums[i] = 1;  // nums[i]一开始的时候赋值为1
            dp[i] = 1;
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        num[i] = num[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        num[i] += num[j];
                    } else
                        continue;
                }
            //注意要思路清晰
            //如果dp[j]+1>dp[i]的话
            //说明dp[i]要进行更新,那么有 num[i]=num[j];
            //否则就是num[i]+=num[j];
            max_num = max(max_num, dp[i]);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (dp[i] == max_num)
                cnt += num[i];
        return cnt;
    }

   private:
    //在private对象里面的dp和num会自动初始化为0
    int dp[2001];
    int num[2001];
};