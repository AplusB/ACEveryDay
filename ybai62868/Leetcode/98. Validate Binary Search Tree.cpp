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
    bool chk ( TreeNode * n, long long & preVal ){
        if ( n==NULL ) return true;
        if ( !chk(n->left,preVal)) return false;
        if ( n->val <= preVal ) return false;
        else preVal = n->val;
        if ( !chk(n->right,preVal)) return false;
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        long long preVal = LONG_MIN;
        return chk(root,preVal);
    }
};
