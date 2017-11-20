class Solution {
public:
    bool isPalindrome(int x) {
        
        int y = 0;
        for(int i = x; i != 0; i /= 10)
            y = i % 10 + y * 10;
        
        return y < 0 ? false : y == x;
    }
};