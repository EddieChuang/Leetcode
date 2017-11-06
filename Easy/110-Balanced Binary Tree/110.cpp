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
    bool isBalanced(TreeNode* root) {
        
        if(!root)
            return true;
        
        int lheight = heigh(root->left, 1);
        int rheight = heigh(root->right, 1);
        
        
        return abs(lheight-rheight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        
    }
    
    int heigh(TreeNode *root, int depth){
        
        if(!root)
            return depth;
        
        return max(heigh(root->left, depth+1), heigh(root->right, depth+1));
    }
    
};