
//如果我的层序遍历需要能够逐层输出呢?

//可以考虑cpp里面的pair,把节点的深度也一并存入队列中去
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
        //可以考虑记录每个节点的深度连带着在队列里面
        // pair的使用方法
        //使用make_pair()创建pair对象
        //使用.first,.second来访问元素
        if (root == nullptr) {
            return vector<vector<int>>();
        }
        //可以使用pair
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> ans;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            //可以通过记录节点的深度来逐层遍历
            pair<TreeNode*, int> p = q.front();
            q.pop();
            if (ans.size() < p.second + 1) {
                ans.push_back(vector<int>());  //防止指针访问越界
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