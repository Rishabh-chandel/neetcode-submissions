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
    vector<int> ans;
    void f(TreeNode* node,int lvl) {
        if(!node) return;
        if(ans.size() == lvl) ans.push_back(node->val);
        f(node->right,lvl+1);
        f(node->left,lvl+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        f(root,0);
        return ans;
    }
};
