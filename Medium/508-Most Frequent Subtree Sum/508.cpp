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
        
        if(!root)
            return vector<int>();
        
        map<int, int> freq;
        subTreeSum(root, freq);
        
        vector<pair<int, int>> vecPair(freq.begin(), freq.end());
        sort(vecPair.begin(), vecPair.end(), CompareByValue());
        
        vector<int> ans;
        ans.push_back(vecPair[0].first);
        for(int i = 1; i < vecPair.size(); ++i){
            if(vecPair[i].second != vecPair[i-1].second)
                break;
            ans.push_back(vecPair[i].first);
        }
        
        
        return ans;
    }
    
    int subTreeSum(TreeNode *root, map<int, int> &freq){
        
        if(!root)
            return 0;
        
        int sum = root->val;
        sum += subTreeSum(root->left, freq);
        sum += subTreeSum(root->right, freq);
        
        ++freq[sum];
        return sum;
    }

private:
    
    static bool compareByValue(const pair<int, int> &lhs, const pair<int, int> &rhs){
        return lhs.second > rhs.second;
    }
    
    struct CompareByValue{
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs){
            return lhs.second > rhs.second;
        }
    };
    
};