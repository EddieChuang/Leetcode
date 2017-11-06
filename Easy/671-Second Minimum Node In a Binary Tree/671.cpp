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
    int findSecondMinimumValue(TreeNode* root) {
        
        int min = -1, min_sec = -1;
        DFS(root, min, min_sec);
        return min_sec;
    }
    
    void DFS(TreeNode *root, int &min, int &min_sec){
        
        if(!root)
            return;
        
        if(root->val <= min || min == -1)
            min = root->val;
        else if(root->val < min_sec || min_sec == -1)
            min_sec = root->val;
        
        
        DFS(root->left, min, min_sec);
        DFS(root->right, min, min_sec);
    }
    
};