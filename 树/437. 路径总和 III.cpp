
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
    unordered_map<int, int> prefix;

    int dfs(TreeNode* root, int curr, int targetSum) {
        if (root == nullptr)
            return 0;

        curr = curr + root->val;
        int ret = 0;
        if (prefix.count(curr - targetSum)) {
            ret += prefix[curr - targetSum];
        }
        prefix[curr]++;
        ret += dfs(root->left, curr, targetSum);
        ret += dfs(root->right, curr, targetSum);
        prefix[curr]--;
        return ret;
    }
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }
};