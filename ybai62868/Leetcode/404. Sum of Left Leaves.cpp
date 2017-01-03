/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        dfs(root,res,false);
        return res;
    }
    void dfs( TreeNode * root, int & res, bool isleft ) {
        if ( root==NULL ) return;
        if ( root->left||root->right ) {
            dfs(root->left,res,true);
            dfs(root->right,res,false);
        }
        else if ( isleft ) {
            res+=root->val;
        }
    }
};
