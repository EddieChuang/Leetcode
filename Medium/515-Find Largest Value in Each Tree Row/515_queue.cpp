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
    vector<int> largestValues(TreeNode* root) {
        
        vector<int> ans;
        
        if(!root)
            return ans;
        
        queue<TreeNode*> treeQueue;
        queue<int> depthQueue;
        treeQueue.push(root);
        depthQueue.push(0);
        
        while(!treeQueue.empty()){
            
            TreeNode *node = treeQueue.front(); treeQueue.pop();
            int depth = depthQueue.front(); depthQueue.pop();
            
            if(ans.size() <= depth)
                ans.push_back(node->val);
            else if(ans[depth] < node->val)
                ans[depth] = node->val;
            
            if(node->left){
                treeQueue.push(node->left);
                depthQueue.push(depth+1);
            }
            if(node->right){
                treeQueue.push(node->right);
                depthQueue.push(depth+1);
            }
        }
        return ans; 
    }
};