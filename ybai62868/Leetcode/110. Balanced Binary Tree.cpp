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
    int depth( TreeNode * n ) {
        if ( n==NULL ) return 0;
        return max(depth(n->left),depth(n->right))+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if ( root==NULL ) return true;
        return (isBalanced(root->left)&&isBalanced(root->right)&&abs(depth(root->left)-depth(root->right))<=1);
    }
};
