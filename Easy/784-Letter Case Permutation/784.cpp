class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        
        vector<string> ans;
        backtracking(ans, S, 0);
        return ans;
    }
    
    void backtracking(vector<string>& ans, string S, int pos){
        
        
        int i;
        for(i = pos; i < S.size(); ++i){
            if(isalpha(S[i])){
                backtracking(ans, S, i+1);
                S[i] = isupper(S[i]) ? tolower(S[i]) : toupper(S[i]);
                backtracking(ans, S, i+1);
                break;
            }    
        }
        if(i == S.size())
            ans.push_back(S);
        
    }
    
};