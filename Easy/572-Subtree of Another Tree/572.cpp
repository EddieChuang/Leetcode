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
    bool isSubtree(TreeNode* s, TreeNode* t) {

        if(!s)
            return false;
        
        bool isSub = s->val==t->val ? equal(s, t) : false;
        
        return isSub || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    
    bool equal(TreeNode *s, TreeNode *t){
        
        if(!s || !t)
            return s == t;
        if(s->val != t->val)
            return false;
        
        return equal(s->left, t->left) && equal(s->right, t->right);
    }
    
};