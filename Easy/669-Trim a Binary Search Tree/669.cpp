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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        
        if(!root)
            return NULL;
        
        TreeNode *node = new TreeNode(root->val);
        node->left  = trimBST(root->left, L, R);
        node->right = trimBST(root->right, L, R); 
        if(root->val >= L && root->val <= R)
            return node;
        else if(root->val < L)
            return node->right;
        else if(root->val > R)
            return node->left;
    }
};