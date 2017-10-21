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
        
        return DFS(root, false);
    }
    
    int DFS(TreeNode *root, bool isLeft)
    {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return isLeft ? root->val : 0;

        return DFS(root->left, true) + DFS(root->right, false);
    }
};