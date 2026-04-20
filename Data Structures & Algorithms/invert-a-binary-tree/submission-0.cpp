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
    TreeNode* rev_t(TreeNode* node) {
        if(!node) return NULL;
        TreeNode* l = rev_t(node->left);
        TreeNode* r = rev_t(node->right);
        node->left = r;
        node->right = l;
        return node;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        return rev_t(root);
    }
};
