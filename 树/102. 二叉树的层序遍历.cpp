
#include <iostream>
#include <queue>
#include <utility>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return vector<vector<int>>();
        }
        //可以使用pair
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> ans;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            pair<TreeNode*, int> p = q.front();
            q.pop();
            if (ans.size() < p.second + 1) {
                ans.push_back(vector<int>());
            }
            ans[p.second].push_back(p.first->val);
            if (p.first->left) {
                q.push(make_pair(p.first->left, p.second + 1));
            }
            if (p.first->right) {
                q.push(make_pair(p.first->right, p.second + 1));
            }
        }
        return ans;
    }
};