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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p || !q) return p == q;
        int l = isSameTree(p->left,q->left);
        int r = isSameTree(p->right,q->right);
        if(p->val != q->val) return 0; 
        return l && r;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* sub) {
        if(!sub) return true;
        if(!root) return false;
        if(isSameTree(root,sub)) return 1;
        bool l = isSubtree(root->left,sub);
        bool r = isSubtree(root->right,sub);
        return l || r;
    }
};
