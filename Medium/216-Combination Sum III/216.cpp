class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> vec;
        helper(vec, 1, k, n);
        return ans;
    }
    
    void helper(vector<int> vec, int num, int k, int n){

        if(k == 0)
            return;
        
        for(int i = num; i <= 9; ++i){
            vec.push_back(i);
            if(n - i > 0)
                helper(vec, i+1, k-1, n-i);
            else if(n - i == 0 && k == 1)
                ans.push_back(vec);
            else if(n - i < 0)
                break;
            vec.pop_back();
        }
    }
    
    vector<vector<int>> ans;
    
};