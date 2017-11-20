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
    int minDepth(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int min_depth = 1000000;
        DFS(root, min_depth, 1);
        return min_depth;
    }
    
    void DFS(TreeNode *root, int &min_depth, int depth)
    {
        if(!root->left && !root->right)
        {
            min_depth = min(min_depth, depth);
            return;
        }
        
        if(root->left)
            DFS(root->left, min_depth, depth + 1);
        if(root->right)
            DFS(root->right, min_depth, depth + 1);
    }
    
};