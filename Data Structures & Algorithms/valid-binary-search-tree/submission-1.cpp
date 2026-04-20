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
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return NULL;
        queue<pair<pair<TreeNode*,int>,int>> q;
        q.push({{root,INT_MIN},INT_MAX});
        while(!q.empty()) {
            auto tp = q.front();
            q.pop();
            TreeNode* node = tp.first.first;
            int mini = tp.first.second;
            int maxi = tp.second;
            int val = node->val;
            if(val >= maxi || val <= mini) return 0;
            if(node->left) q.push({{node->left,mini},val});
            if(node->right) q.push({{node->right,val},maxi});
        }
        return 1;
    }
};
