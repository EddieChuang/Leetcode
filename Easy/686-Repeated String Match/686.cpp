class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        
        int n = B.size() < A.size() ? 1 : B.size() / A.size();
        string str = "";
        for(int i = 0; i < n; ++i)
            str += A;
        
        if(str.find(B) != string::npos)
            return n;
        if((str+A).find(B) != string::npos)
            return n + 1;
        
        return -1;
    }
};