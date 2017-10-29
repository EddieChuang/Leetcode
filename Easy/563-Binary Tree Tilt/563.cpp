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
    int findTilt(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int tilt = findTilt(root->left) + findTilt(root->right);
        int lval = root->left  ? root->left->val  : 0;
        int rval = root->right ? root->right->val : 0;
        root->val += lval + rval;
        return abs(lval - rval) + tilt;
    }
};