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
    void getInorderData(TreeNode * root, vector<int>& res){
        if ( root == NULL ) return;
        getInorderData(root->left,res);
        res.push_back(root->val);
        getInorderData(root->right,res);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        if ( root == NULL ) return res;
        getInorderData(root,res);
        return res;
    }
};
