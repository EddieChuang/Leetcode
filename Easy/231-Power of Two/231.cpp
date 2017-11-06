class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        /*
            if(n&(n-1) == 0 && n >= 1)
                return true;
            return false;
        */
        
        while(n)
        {
            if(n == 1)
                return true;
            else if(n % 2)
                return false;
            n /= 2;
        }
        return false;
    }
};