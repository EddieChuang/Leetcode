class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        
        int *dp = new int[nums.size()];
        dp[0] = nums[0];
        dp[1] = nums[1];
        
        for(int i = 2; i < nums.size(); ++i)
        {
            dp[i] = nums[i] + dp[i-2];
            for(int j = i-3; j >= 0; --j)
                dp[i] = max(dp[i], nums[i] + dp[j]);
        }
        return max(dp[nums.size()-1], dp[nums.size()-2]);
    }
};