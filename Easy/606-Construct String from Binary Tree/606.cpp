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
    string tree2str(TreeNode* t) {
        
        if(!t)
            return "";
        
        string str = to_string(t->val);
        
        if(t->right)
        {
            str += "(" + tree2str(t->left) + ")";
            str += "(" + tree2str(t->right) + ")";
        }
        else if(t->left)
            str += "(" + tree2str(t->left) + ")";
        return str;
    }
};