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
    vector<string> binaryTreePaths(TreeNode* root) {
        
        
        if(!root)
            return vector<string>();
        if(!root->left && !root->right)
             return vector<string>(1, to_string(root->val));
        
        string curr = to_string(root->val);
        vector<string> path, left, right;
        if(root->left)
            left = binaryTreePaths(root->left);
        if(root->right)
            right = binaryTreePaths(root->right);
        
        for(int i = 0; i < left.size(); ++i)
            path.push_back(curr + "->" + left[i]);
        for(int i = 0; i < right.size(); ++i)
            path.push_back(curr + "->" + right[i]);
        
        return path;
    }
    
};