class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int *dp = new int[nums.size()];
        int max_sum = dp[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            dp[i] = max(nums[i], nums[i]+dp[i-1]);
            max_sum = max(dp[i], max_sum);    
        }
        return max_sum;
    }
};