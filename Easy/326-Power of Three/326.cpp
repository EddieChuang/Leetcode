class Solution {
public:
    bool isPowerOfThree(int n) {
        
        if(n == 1)
            return true;
        else if(n % 3 || !n)
            return false;
        
        return isPowerOfThree(n/3);
    }
};