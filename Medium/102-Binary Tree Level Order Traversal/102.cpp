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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> levelOrders;
        traverse(levelOrders, root, 0);
        return levelOrders;        
    }
    
    
    void traverse(vector<vector<int>> &levelOrders, TreeNode *node, int level){
        
        if(!node){
            return;
        }
        
        if(level == levelOrders.size()){
            levelOrders.push_back(vector<int>(1, node->val));
        } else {
            levelOrders[level].push_back(node->val);
        }
        
        traverse(levelOrders, node->left, level + 1);
        traverse(levelOrders, node->right, level + 1);
    }
    
};