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
        
				DFS(root, 0);
				vector<double> ans;
				for(int i = 0; i < maxDepth; ++i){
					ans.push_back(sum[i] / num[i]);
				}
				return avg;
    }

		void DFS(TreeNode *root, int depth){

				if(!root) return;

				++num[depth];
				sum[depth] += root->val;
				maxDepth = max(maxDepth, depth);
				
				DFS(root->left, depth+1);
				DFS(root->right, depth+1);
		}

		double sum[1000] = { 0 };
		int num[1000] = { 0 };
		int maxDepth = 0;
		// vector<int> sum;
		// vector<int> num;

};