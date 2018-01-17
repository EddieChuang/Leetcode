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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        return build(nums, 0, nums.size());
    }

    TreeNode* build(vector<int> nums, int front, int end){
        
        if(front < end){
            int pivot = std::max_element(nums.begin()+front, nums.begin()+end) - nums.begin();
            TreeNode *node = new TreeNode(nums[pivot]);
            node->left = build(nums, front, pivot);
            node->right = build(nums, pivot+1, end);
            return node;
        }
        return NULL;
    }

    /*
    void mergeSort(vector<int> &vec, int front, int end){
        
        if(front < end){
            int mid = (front + end) / 2;
            mergeSort(vec, front, mid);
            mergeSort(vec, mid+1, end);
            merge(vec, front, mid, end);
        }
    }
    
    void merge(vector<int> &vec, int front, int mid, int end){
        
        vector<int> left(vec.begin()+front, vec.begin()+mid+1);
        vector<int> right(vec.begin()+mid+1, vec.begin()+end+1);
        
        left.push_back(-1);
        right.push_back(-1);
        int left_idx = 0, right_idx = 0;
        
        for(int i = front; i <= end; ++i){
            if(left[left_idx] >= right[right_idx])
                vec[i] = left[left_idx++];
            else
                vec[i] = right[right_idx++];
        }
        
    }
    */
    
};