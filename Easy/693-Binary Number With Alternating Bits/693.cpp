class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        int prev = n % 2;
        n /= 2;
        while(n)
        {
            if(prev == n % 2)
                return false;
            prev = n % 2;
            n /= 2;
        }
        return true;
    }
};