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
    int kthSmallest(TreeNode* root, int k) {
        
        DFS(root, k);
        return min;
    }
    
    void DFS(TreeNode *root, int &k){
        

        if(root->left)
            DFS(root->left, k);
        if(--k == 0){
            min = root->val;
            return;
        }
        if(root->right)
            DFS(root->right, k);
        
    }
    
    int min;
    
};