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
    bool f(TreeNode* node,long long mini,long long maxi) {
        if(!node) return true;
        int val = node->val;
        if(val <= mini || val >= maxi) return false;
        bool l = f(node->left,mini,val);
        if(!l) return false;
        bool r = f(node->right,val,maxi);
        return l && r;
    }
public:
    bool isValidBST(TreeNode* root) {
        return f(root,-1e18,1e18);
    }
};
