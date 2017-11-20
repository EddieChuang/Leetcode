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
    bool hasPathSum(TreeNode* root, int sum) {
        
        if(!root)
            return false;
        
        if(root->left)
            root->left->val += root->val;

        if(root->right)
            root->right->val += root->val;

        return (!root->left && !root->right) ? root->val==sum : hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};