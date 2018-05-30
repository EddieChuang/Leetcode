class Solution {
public:
    int minDistance(string word1, string word2) {

        int len = LongestCommonSubstringLen(word1, word2);
        return (word1.size() - len) + (word2.size() - len);
    }

    int LongestCommonSubstringLen(string word1, string word2){
        
        int m = word1.size();
        int n = word2.size();
        int **dp = new int*[m + 1];
        for(int i = 0; i < m + 1; ++i){
            dp[i] = new int[n + 1];
            dp[i][0] = 0;
        }
        for(int j = 0; j < n + 1; ++j)
            dp[0][j] = 0;

        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};