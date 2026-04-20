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
    vector<int> in;
    void f(TreeNode* node) {
        if(!node) return;
        f(node->left);
        in.push_back(node->val);
        f(node->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        f(root);
        return in[k-1];
    }
};
