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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(!p || !q)
            return p == q;    
        else if(p->val != q->val)
            return false;
        
        bool left_equal = isSameTree(p->left, q->left);
        bool right_equal = isSameTree(p->right, q->right);
        
        return left_equal && right_equal;
    }
};