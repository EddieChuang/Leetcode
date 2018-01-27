class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> dp(temperatures.size(), 0);
        for(int i = temperatures.size()-2; i >= 0; --i){
            for(int j = 1; j+i < temperatures.size(); ++j){
                if(temperatures[i] < temperatures[j+i]){
                    dp[i] = j;
                    break;
                }
                else if(temperatures[i] == temperatures[j+i]){
                    dp[i] = dp[j+i]==0 ? 0 : dp[j+i] + j;
                    break;
                }
            }
        }
        return dp;
    }
};