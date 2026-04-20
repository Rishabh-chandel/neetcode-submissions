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
    int f(TreeNode* node,int maxi) {
        if(!node) return 0;
        int val = (node->val >= maxi) ? 1 : 0;
        maxi = max(maxi,node->val);
        val += f(node->left,maxi);
        val += f(node->right,maxi);
        return val;
    }
public:
    int goodNodes(TreeNode* root) {
        return f(root,-101);
    }
};
