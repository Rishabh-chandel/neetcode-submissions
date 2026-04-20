/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    vector<vector<int>> ans;
    void f(TreeNode* node,int lvl) {
        if(!node) return;
        if(lvl == ans.size()) ans.push_back(vector<int>());
        ans[lvl].push_back(node->val);
        f(node->left,lvl+1);
        f(node->right,lvl+1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        f(root,0);
        return ans;
    }
};
