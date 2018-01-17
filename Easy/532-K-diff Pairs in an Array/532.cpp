class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        mergeSort(nums, 0, nums.size()-1);
        set<pair<int, int>> pair_set;
        int count = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = i+1; j < nums.size(); ++j)
            {
                if(nums[j]-nums[i] == k && pair_set.count(pair<int, int>(nums[j], nums[i])) == 0)
                {
                    pair_set.insert(pair<int, int>(nums[j], nums[i]));
                    count++;
                    break;
                }
                else if(nums[j]-nums[i] > k)
                    break;
            }
        }
        return count;
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
        vector<int> left(nums.begin()+front, nums.begin()+mid+1);
        vector<int> right(nums.begin()+mid+1, nums.begin()+end+1);
        left.push_back(10000001);
        right.push_back(10000001);
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