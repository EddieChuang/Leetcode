/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        curr = 0;
        build_iterator(root);
    }
    
    void build_iterator(TreeNode *root){
        if(!root)
            return;
        
        if(root->left)
            build(root->left);
        vec.push_back(root->val);
        if(root->right)
            build(root->right);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return curr < vec.size();
    }

    /** @return the next smallest number */
    int next() {
        return vec[curr++];
    }
    
    vector<int> vec;
    int curr;
    
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */