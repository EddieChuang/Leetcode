class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        int *dp = new int[n+1];
        dp[0] = 1;
        for(int i = 1; i <= n; ++i)
            dp[i] = dp[i-1] + uniqueDigit(i);
        
        return dp[n];
    }
    
    int uniqueDigit(int n){
        
        int count = 9;
        for(int i = 0; i < n-1; ++i)
            count *= (9-i);
        return count;
    }
};