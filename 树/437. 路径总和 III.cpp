//两种方法
//采用双递归或是前缀和

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

#include <map>
#include <unordered_map>
using namespace std;
class Solution {
   public:
    //采用前缀和的方法
    // cpp
    unordered_map<int, int> prefix;  //保存前缀和
    // curr表示当前的前缀和,为什么要开long long呢,稍微思考一下之后
    int dfs(TreeNode* root, int curr, int targetSum) {
        if (root == nullptr)  //表示递归到底
            return 0;
        //才用的是中序遍历的方法
        //得充分弄清楚递归的函数的含义才行
        //表示的是到当前节点及以下所有节点的个数
        //每次回溯的时候记得去掉
        curr = curr + root->val;  //表示当前的curr
        int ret = 0;
        if (prefix.count(curr - targetSum)) {
            ret += prefix[curr - targetSum];
        }  //注意这是一个hash_map的要求
        prefix[curr]++;
        ret += dfs(root->left, curr, targetSum);
        ret += dfs(root->right, curr, targetSum);
        prefix[curr]--;
        return ret;
    }
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;  //表示到这个节点恰好是满足的,所以空路径=1是必须的
        return dfs(root, 0, targetSum);
    }
};