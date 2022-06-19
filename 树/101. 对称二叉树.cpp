#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};
class Solution {
   public:
    bool isGood(TreeNode* l, TreeNode* r) {
        if (l == nullptr && r == nullptr)
            return true;
        if (l == nullptr || r == nullptr || l->val != r->val)
            return false;
        return isGood(l->right, r->left) && isGood(l->left, r->right);
    }
    bool isSymmetric(TreeNode* root) { return isGood(root->left, root->right); }
};