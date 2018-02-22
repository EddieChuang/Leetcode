class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        backtracking(ans, "", n, n);
        return ans;
    }
    
    void backtracking(vector<string>& ans, string str, int lParan, int rParan){
        
        if(lParan == 0 && rParan == 0){
            ans.push_back(str);
            return;
        }
        
        if(lParan > 0)
            backtracking(ans, str+"(", lParan-1, rParan);
        if(rParan > 0 && lParan < rParan)
            backtracking(ans, str+")", lParan, rParan-1);

    }
    
};