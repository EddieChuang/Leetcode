class Solution {
public:
    int arrangeCoins(int n) {
        
        for(int i = 0; true; i++, n -= i)
            if(n <= 0)
                return n==0 ? i : i-1;
    }
};