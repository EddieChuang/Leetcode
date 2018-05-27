class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        
        return helper(input);
    }
    
    vector<int> helper(string input) {
        
        vector<int> vec;
        int size = input.size();
        for(int i = 0; i < size; ++i){
            
            char c = input[i];
            if(c == '+' || c == '-' || c == '*'){
                
                string leftExpr   = input.substr(0, i);
                string rightExpr  = input.substr(i+1);
                // cout << leftExpr << " " << rightExpr << endl;
                vector<int> left  = dp.find(leftExpr)  == dp.end() ? helper(leftExpr)  : dp[leftExpr];
                vector<int> right = dp.find(rightExpr) == dp.end() ? helper(rightExpr) : dp[rightExpr];
                dp[leftExpr]  = left;
                dp[rightExpr] = right;
                
                for(auto lVal : left){
                    for(auto rVal : right){
                        if(c == '+')
                            vec.push_back(lVal + rVal);
                        else if(c == '-')
                            vec.push_back(lVal - rVal);
                        else if(c == '*')
                            vec.push_back(lVal * rVal);
                    }
                }
                
            }
            
        }
        
        if(vec.empty())
            vec.push_back(stoi(input));
        
        return vec;
    }
    
    map<string, vector<int>> dp;
};