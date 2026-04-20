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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p || !q) return p == q;
        queue<TreeNode*> q1 , q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()) {
            if(q1.size() != q2.size()) return false;
            int sz = q1.size();
            while(sz--) {
                TreeNode* n1 = q1.front(); q1.pop();
                TreeNode* n2 = q2.front(); q2.pop();
                if(n1->val != n2->val) return false;
                if((n1->left == nullptr) != (n2->left == nullptr)) return false;
                if((n1->right == nullptr) != (n2->right == nullptr)) return false;
                if(n1->left) q1.push(n1->left);
                if(n1->right) q1.push(n1->right);
                if(n2->left) q2.push(n2->left);
                if(n2->right) q2.push(n2->right);
            }
        }
        return q1.empty() && q2.empty();
    }
};
