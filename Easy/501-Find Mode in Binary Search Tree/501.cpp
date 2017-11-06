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
    vector<int> findMode(TreeNode* root) {
        
        map<int, int> count;
        DFS(root, count);
        
        vector<int> ans;
        int max = 0;
        for(map<int, int>::iterator it = count.begin(); it != count.end(); it++)
        {
            if(max < it->second)
            {
                ans.clear();
                ans.push_back(it->first);
                max = it->second;
            }
            else if(max == it->second)
                ans.push_back(it->first);
        }
        
        return vector<int>();
    }
    
    void DFS(TreeNode *root, map<int, int> &count)
    {
        if(!root)
            return;
        
        count[root->val]++;
        DFS(root->left, count);
        DFS(root->right, count);
    }
    
};