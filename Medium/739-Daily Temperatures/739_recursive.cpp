class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> dp(temperatures.size(), 0);
        for(int i = temperatures.size()-2; i >= 0; --i)
            greedy(temperatures, dp, i, 1);
        return dp;
    }
    
    void greedy(vector<int> temperatures, vector<int> &dp, int now, int next){
        
        if(now+next >= temperatures.size())
            return;
        
        int future = now+next;
        if(temperatures[now] < temperatures[future])
            dp[now] = next;
        else if(temperatures[now] == temperatures[future])
            dp[now] = dp[future]==0 ? 0 : dp[future] + next;
        else
            greedy(temperatures, dp, now, next+1);
    }
};