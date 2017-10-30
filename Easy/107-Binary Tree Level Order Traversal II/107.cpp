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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> order;
        if(!root)
            return order;
        
        level_order(root, order, 1);
        reverse(order.begin(), order.end());
        
        return order;
    }
    
    void level_order(TreeNode *root, vector<vector<int>> &order ,int depth)
    {
        if(order.size() < depth)
            order.push_back(vector<int>());
        
        if(root->left)
            level_order(root->left, order, depth+1);
        
        order[depth-1].push_back(root->val);
        
        if(root->right)
            level_order(root->right, order, depth+1);
    }
    
};