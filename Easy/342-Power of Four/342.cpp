class Solution {
public:
    bool isPowerOfFour(int num) {
        
        if(num == 1)
            return true;
        else if(!num || num % 4)
            return false;
        
        return isPowerOfFour(num/4);
    }
};