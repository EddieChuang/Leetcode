class Solution {
public:
    int climbStairs(int n) {
        
        int step[100] = {1, 2};
        for(int i = 2; i < n; ++i)
            step[i] = step[i-1] + step[i-2];
        return step[n-1];
    }
};