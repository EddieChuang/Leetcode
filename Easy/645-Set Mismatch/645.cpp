class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        mergeSort(nums, 0, nums.size()-1);
        
        int diff = 0;
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i)
            diff += (i+1) - nums[i];
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] == nums[i-1])
            {
                ans.push_back(nums[i]);
                ans.push_back(nums[i]+diff);
                return ans;
            }
        }
    }
    
    void mergeSort(vector<int> &nums, int front, int end)
    {
        if(front < end)
        {
            int mid = (front + end) / 2;
            mergeSort(nums, front, mid);
            mergeSort(nums, mid+1, end);
            merge(nums, front, mid, end);
        }
    }
    
    void merge(vector<int> &nums, int front, int mid, int end)
    {
        vector<int> left(nums.begin() + front, nums.begin() + mid + 1);
        vector<int> right(nums.begin() + mid + 1, nums.begin() + end + 1);
        
        left.push_back(2147483647);
        right.push_back(2147483647);
        
        int idx_left = 0, idx_right = 0;
        for(int i = front; i <= end; ++i)
        {
            if(left[idx_left] <= right[idx_right])
                nums[i] = left[idx_left++];
            else
                nums[i] = right[idx_right++];
        }
        
    }
    
    
};