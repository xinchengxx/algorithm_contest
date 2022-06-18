// 这是一个非常经典的好题
// 关键在于这个找1 非常关键
// 可以极大的简化这个搜索次数
// 很关键
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    // 首先是遍历
    vector<int> smallestMissingValueSubtree(vector<int>& parents,
                                            vector<int>& nums) {
        int n = parents.size();
        vector<int> ans(n, 1);
        int x = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                x = i;
                break;
            }
        }
        if (x == -1)
            return ans;
        // 然后就是遍历这个x下面的子树;
        // 首先反向建立树;
        vector<vector<int>> son(n);
        for (int i = 0; i < parents.size(); i++) {
            if (parents[i] == -1)
                continue;
            int fa = parents[i];
            son[fa].push_back(i);
        }
        vector<int> marks(n, false);
        vector<int> bucket(1e5 + 5, 0);
        // 由于本题的function 关键字不是所有的cpp版本都支持，所以注释掉
        // 如果要修该可以写成外面的函数, 然后所有变量都写在外面就行了
        // function<void(int)> dfs = [&](int v)
        // {
        //     if (marks[v] == true)
        //         return;
        //     bucket[nums[v]] = 1;
        //     marks[v] = true;
        //     for (int i = 0; i < son[v].size(); i++)
        //     {
        //         int s = son[v][i];
        //         dfs(s);
        //     }
        // };
        int k = 1;
        while (parents[x] != -1) {
            // dfs(x);
            while (bucket[k] == 1) {
                k++;
            }
            ans[x] = k;
            x = parents[x];
        }
        // dfs(0);
        while (bucket[k] == 1) {
            k++;
        }
        ans[0] = k;
        return ans;
    }
};