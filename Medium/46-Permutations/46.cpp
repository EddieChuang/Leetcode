class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> vec;
        
        backtracking(vec, nums);
        
        return ans;
    }
    
    void backtracking(vector<int> vec, vector<int> nums){
        
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            vec.push_back(nums[i]);
            if(vec.size() < n && !visited[i]){
                visited[i] = true;
                backtracking(vec, nums);
                visited[i] = false;
            }
            else if(vec.size() == n && !visited[i])
                ans.push_back(vec);
            vec.pop_back();
        }
        
    }
    
    vector<vector<int>> ans;
    bool visited[1000] = {false};
    
};