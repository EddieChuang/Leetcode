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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        int maxCount = 0;
        unordered_map<int, int> freq;
        subTreeSum(root, freq, maxCount);
        
        vector<int> ans;
        for(auto f : freq)
            if(maxCount == f.second)
                ans.push_back(f.first);

        return ans;
    }
    
    int subTreeSum(TreeNode *root, unordered_map<int, int> &freq, int &maxCount){
        
        if(!root)
            return 0;
        
        int sum = root->val;
        sum += subTreeSum(root->left, freq, maxCount);
        sum += subTreeSum(root->right, freq, maxCount);
        
        ++freq[sum];
        maxCount = max(maxCount, freq[sum]);
        
        return sum;
    }

};