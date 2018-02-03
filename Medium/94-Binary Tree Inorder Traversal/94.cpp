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
    vector<int> inorderTraversal(TreeNode* root) {
        
        inorder(root);
        return ans;
    }
    
    void inorder(TreeNode *root){
        
        if(!root)
            return;
        
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    

private:
    vector<int> ans;
    
};