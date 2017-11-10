class Solution {
public:
    string reverseWords(string s) {
        
        for(int i = 0, j = 0; i <= s.size(); ++i)
        {
            if(i == s.size() || s[i] == ' ')
            {
                for(int n = 0; n < (i-j) / 2; ++n)
                    swap(s[j+n], s[i-n-1]);
                
                j = i + 1;
            }
        }
        return s;
    }
};