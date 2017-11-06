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
        
        setHeigh(root);
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            
            if(!node)
                continue;
            
            int lheigh = node->left  ? node->left->val  : 0;
            int rheigh = node->right ? node->right->val : 0;
            
            if(abs(lheigh - rheigh) > 1)
                return false;
            q.push(node->left);
            q.push(node->right);
        }
        return true;
    }
    
    void setHeigh(TreeNode *root){
        
        if(!root->left && !root->right)
            root->val = 1;
        else
        {
            int lheight = 0, rheight = 0;
            if(root->left)
            {
                setHeigh(root->left);
                lheight = root->left->val;
            }
            if(root->right)
            {
                setHeigh(root->right);
                rheight = root->right->val;
            } 
            root->val = max(lheight, rheight) + 1;
        }
    }
    
};