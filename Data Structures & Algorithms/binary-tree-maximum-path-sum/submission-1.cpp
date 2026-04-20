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
    int sum = 0 , maxi = -1e9;
    int flag = 0;
    int f(TreeNode* node) {
        if(!node) return 0;
        if(node->val >= 0) flag = 1;
        if(node->val < 0) maxi = max(maxi,node->val);
        int lsum = max(0,f(node->left));
        int rsum = max(0,f(node->right));
        int sumi = node->val+lsum+rsum;
        if(sumi <= 0) return 0;
        sum = max(sum,sumi);
        return max(lsum,rsum)+node->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        f(root);
        return flag == 1 ? sum : maxi;  
    }
};
