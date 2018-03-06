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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        if(!root)
            return ans;
        
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        while(!nodeStack.empty()){
            
            TreeNode *node = nodeStack.top(); nodeStack.pop();
            
            ans.push_back(node->val);
            
            if(node->right)
                nodeStack.push(node->right);
            if(node->left)
                nodeStack.push(node->left);
        }
        return ans;
    }

    
};