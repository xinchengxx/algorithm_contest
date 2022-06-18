#include <iostream>
#include <vector>
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return vector<vector<int>>();
        vector<vector<int>> ans;
        vector<int> nums;
        trackBack(root, targetSum, ans, nums);
        return ans;
    }
    void trackBack(TreeNode* root,
                   int tar,
                   vector<vector<int>>& ans,
                   vector<int>& nums) {
        if (root->left == nullptr && root->right == nullptr) {
            if (tar == root->val) {
                nums.push_back(root->val);
                ans.push_back(nums);
                nums.pop_back();
            }
            return;
        }
        nums.push_back(root->val);
        if (root->left)
            trackBack(root->left, tar - root->val, ans, nums);
        if (root->right)
            trackBack(root->right, tar - root->val, ans, nums);
        nums.pop_back();
    }
};