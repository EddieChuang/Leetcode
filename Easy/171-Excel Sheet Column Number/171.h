class Solution {
public:
    int titleToNumber(string s) {
        
        int x = 1, sum = 0;
        for(int i = s.size()-1 ; i >= 0; --i, x *= 26)
            sum += (s[i]-'A'+1) * x;
        return sum;
    }
};