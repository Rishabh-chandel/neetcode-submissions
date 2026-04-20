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
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        int cnt = 0 , ans = -1;
        TreeNode* node = root;
        while(node) {
            if(!node->left) {
                cnt++;
                if(cnt == k) ans = node->val;
                node = node->right;
            }
            else {
                TreeNode* nxt = node->left;
                while(nxt->right && nxt->right != node) {
                    nxt = nxt->right;
                }
                if(!nxt->right) {
                    nxt->right = node;
                    node = node->left;
                }
                else {
                    nxt->right = NULL;
                    cnt++;
                    if(cnt == k) ans = node->val;
                    node = node->right;
                }
            }
        }
        return ans;
    }
};
