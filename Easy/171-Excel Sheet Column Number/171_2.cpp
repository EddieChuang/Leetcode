class Solution {
public:
    int titleToNumber(string s) {
        
        int number = 0;
        for(int i = s.size()-1, x = 1; i >= 0; --i, x *= 26)
            number += (s[i]-'A'+1) * x;
        return number;
    }
};