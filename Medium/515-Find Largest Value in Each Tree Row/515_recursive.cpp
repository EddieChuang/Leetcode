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
        DFS(root, 0);
        return ans;
    }
    
    void DFS(TreeNode *root, int depth){
        if(!root)
            return;
        
        if(ans.size() <= depth)
            ans.push_back(root->val);
        else if(ans[depth] < root->val)
            ans[depth] = root->val;
            
        
        DFS(root->left, depth+1);
        DFS(root->right, depth+1);
    }

private:
    vector<int> ans;
    
};