class Solution {
public:
    bool validPalindrome(string s) {
        
        int n = s.size();
        for(int i = 0, j = n-1; i < j; ++i, --j)
            if(s[i] != s[j])
                return isPalindrome(s.substr(i+1, n-i*2-1)) || isPalindrome(s.substr(i, n-i*2-1));    
        return true;
    }
    
    bool isPalindrome(string s){
        for(int i = 0, j = s.size()-1; i < j; ++i, --j)
            if(s[i] != s[j])
                return false;
        return true;
    }
    
};