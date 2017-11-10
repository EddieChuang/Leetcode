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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> ans;
        vector<vector<int>> vec;
        getAllValue(root, vec, 1);
        
        for(int i = 0; i < vec.size(); ++i)
        {
            double sum = 0;
            for(int j = 0; j < vec[i].size(); ++j)
                sum += vec[i][j];
            ans.push_back(sum / vec[i].size());
        }
        return ans;
    }
    
    void getAllValue(TreeNode *root, vector<vector<int>> &vec, int depth)
    {
        if(vec.size() < depth)
            vec.push_back(vector<int>());
        
        vec[depth-1].push_back(root->val);
        if(root->left)
            getAllValue(root->left, vec, depth + 1);
        if(root->right)
            getAllValue(root->right, vec, depth + 1);
    }
    
};
