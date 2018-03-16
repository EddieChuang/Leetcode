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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        
        return DFS(root, v, d-1);
    }
    
    TreeNode* DFS(TreeNode* root, int v, int d){
        
        if(!root)
            return NULL;
        
        if(d == 0){
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        } else if(d == 1){
            TreeNode* lTree = new TreeNode(v);
            TreeNode* rTree = new TreeNode(v);
            
            lTree->left = root->left;
            root->left  = lTree;
            
            rTree->right = root->right;
            root->right  = rTree;
            
        } else {
            root->left  = DFS(root->left, v, d-1);
            root->right = DFS(root->right, v, d-1);
        }
        return root;
    }
    
};