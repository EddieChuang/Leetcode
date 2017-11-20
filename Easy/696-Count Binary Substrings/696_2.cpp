class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int count = 0, prev = 0, curr = 1;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == s[i+1] && i < s.size()-1)
                curr++;
            else
            {
                count += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }
        return count;        
    }
};