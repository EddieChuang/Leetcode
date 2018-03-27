class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int dp[500001] = {0};
        dp[1] = prices[1] - prices[0] - fee;
        for(int i = 2; i < prices.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(i == j+1)
                    dp[i] = max(dp[i], max(prices[i]-prices[j]-fee, dp[j]));
                else
                    dp[i] = max(dp[i], max(prices[i]-prices[j]-fee, dp[j]+(prices[i]-prices[j+1])-fee));
            }
        }
        return dp[prices.size()-1];
    }
};