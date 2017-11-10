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
        
        
        queue<TreeNode*> q;
        vector<double> ans;
        q.push(root);
        while(!q.empty())
        {
            double size = q.size();
            double sum  = 0;
            for(int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front(); q.pop();
                sum += node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ans.push_back(sum / size);
        }
        return ans;
    }

    
};
