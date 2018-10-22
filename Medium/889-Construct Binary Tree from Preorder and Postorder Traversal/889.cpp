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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return construct(pre, post);
    }
    
    TreeNode* construct(vector<int> pre, vector<int> post){
    
        if(pre.size() == 0){
            return NULL;
        } else if(pre.size() == 1){
            return new TreeNode(pre[0]);
        } else if(pre.size() == 2){
            TreeNode* root = new TreeNode(pre[0]);
            root->left = new TreeNode(pre[1]);
            return root;
        }
        
        TreeNode* root = new TreeNode(pre[0]);
        
        int endIdx = (find(post.begin(), post.end(), pre[1]) - post.begin()) + 1;
        vector<int> preLeft = vector<int>(pre.begin() + 1, pre.begin() + endIdx + 1);
        vector<int> preRight = vector<int>(pre.begin() + endIdx + 1, pre.end());
        vector<int> postLeft = vector<int>(post.begin(), post.begin() + endIdx);
        vector<int> postRight = vector<int>(post.begin() + endIdx, post.end() - 1);
        
        root->left = construct(preLeft, postLeft);
        root->right = construct(preRight, postRight);
        
        return root;
    }
    
};