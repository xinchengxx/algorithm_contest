#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    bool isSubNode(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return false;
        if (root == p || root == q)
            return true;
        bool ls = isSubNode(root->left, p, q);
        ;
        bool rs = isSubNode(root->right, p, q);
        return ls || rs;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;
        if (root == p && isSubNode(root, nullptr, q))
            return p;
        if (root == q && isSubNode(root, nullptr, p))
            return q;
        bool ls = isSubNode(root->left, p, q);
        bool rs = isSubNode(root->right, p, q);
        if (ls && rs)
            return root;
        else
            return ls ? lowestCommonAncestor(root->left, p, q)
                      : lowestCommonAncestor(root->right, p, q);
    }
};