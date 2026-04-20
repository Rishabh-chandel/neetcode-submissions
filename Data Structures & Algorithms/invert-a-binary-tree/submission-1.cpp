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

// BFS

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* node = root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* tp = q.front();
            q.pop();
            TreeNode* l = tp->left;
            TreeNode* r = tp->right;
            tp->left = r;
            tp->right = l;
            if(tp->left) q.push(tp->left);
            if(tp->right) q.push(tp->right);
        }
        return root;
    }
};
