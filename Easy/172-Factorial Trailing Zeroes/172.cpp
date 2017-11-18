class Solution {
public:
    int trailingZeroes(int n) {
        
        int num = 0;
        for(; n; n /= 5)
            num += n / 5;
         return num;
    }
};