class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        if(nums.size() <= 1)
            return nums.size();
        
        int max_len = 1, len = 1;
        for(int i = 0; i < nums.size() - 1; ++i)
        {
            len = nums[i] < nums[i+1] ? len+1 : 1;
            max_len = max(max_len, len);
        }
        return max_len;
    }
};