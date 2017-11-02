class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int sum = nums.size() * (nums.size()+1) / 2; // accumulate(nums.begin(), nums.end(), 0);
        for(int i = 0; i < nums.size(); ++i)
            sum -= nums[i];
        return sum;
    }
};