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
    TreeNode* build(vector<int>& pre,int prest,int pred,vector<int>& in,int inst,int ined,map<int,int> mpin) {
        if(prest > pred || inst > ined) return NULL;
        TreeNode* root = new TreeNode(pre[prest]);
        int inroot = mpin[pre[prest]];
        int numleft = inroot-inst;
        root->left = build(pre,prest+1,prest+numleft,in,inst,inroot-1,mpin);
        root->right = build(pre,prest+numleft+1,pred,in,inroot+1,ined,mpin);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        map<int,int> mpin;
        for(int i=0;i<n;i++) mpin[in[i]] = i;
        return build(pre,0,n-1,in,0,n-1,mpin);
    }
};
