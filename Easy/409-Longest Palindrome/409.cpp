class Solution {
public:
    int longestPalindrome(string s) {
        
        map<char, int> count;
        for(int i = 0; i < s.size(); ++i)
            count[s[i]]++;
        
        int max_odd = 0, len = 0;
        for(map<char, int>::iterator it = count.begin(); it != count.end(); it++)
        {
            if(it->second % 2)
            {    
                if(it->second > max_odd)
                {    
                    len += max_odd ? max_odd-1: 0;
                    max_odd = it->second;
                }
                else
                    len += it->second-1;
            }
            else
                len += it->second;
        }
        return len + max_odd;
    }
};