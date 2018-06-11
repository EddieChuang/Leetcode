class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int i, j;
        for(i = 0, j = 0; i < s.size() && j < t.size(); ++j){
            if(s[i] == t[j])
                ++i;
        }
        return i == s.size();
        
        // return subSequence(s, t, s.size(), t.size());
        
    }
    
//     bool subSequence(string s, string t, int m, int n){
    
        
//         if (m == 0) 
//             return true;
//         if (n == 0) 
//             return false;

//         if (s[m-1] == t[n-1])
//             return subSequence(s, t, m-1, n-1);

//         return subSequence(s, t, m, n-1);
//     }
    
};