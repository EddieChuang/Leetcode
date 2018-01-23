class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        
        int dp[10000] = {0};
        int sum = 0;
        for (int i = 2; i < A.size(); i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp[i] = dp[i - 1] + 1;
                sum += dp[i];
            }
        }
        return sum;
    }
};