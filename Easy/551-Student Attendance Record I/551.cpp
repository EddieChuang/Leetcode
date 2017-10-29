class Solution {
public:
    bool checkRecord(string s) {
        
        int A = 2, L = 3;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == 'P' || s[i] == 'A')
                L = 3;
            if(s[i] == 'A')
                A--;
            else if(s[i] == 'L')
                L--;
            if(A == 0 || L == 0)
                return false;
        }
        return true;
    }
};