class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return max(nums[0] * nums[1] * nums[n-1], nums[n-1] * nums[n-2] * nums[n-3]);
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
        left.push_back(1001);
        right.push_back(1001);
        
        int idx_left = 0, idx_right = 0;
        for(int i = front; i <= end; ++i)
        {
            if(left[idx_left] < right[idx_right])
                nums[i] = left[idx_left++];
            else
                nums[i] = right[idx_right++];
        }
    }
    
    
};