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
    bool isSymmetric(TreeNode* root) {
        
        vector<vector<int>> vec;
        level(root, vec, 1);
        for(int i = 1; i < vec.size(); ++i) 
            for(int j = 0; j < vec[i].size()/2; ++j)
                if(vec[i][j] != vec[i][vec[i].size()-1-j])
                    return false;
            
        return true;
    }
    
    void level(TreeNode *root, vector<vector<int>> &vec, int depth)
    {
        if(depth > vec.size())
            vec.resize(depth);
        if(!root)
        {
            vec[depth-1].push_back(-1);
            return;
        }
        
        vec[depth-1].push_back(root->val);
        level(root->left, vec, depth+1);
        level(root->right, vec, depth+1);
    }
    
};