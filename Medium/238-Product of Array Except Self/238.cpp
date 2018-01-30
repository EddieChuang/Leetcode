class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> ans;
        int product = 0;
        for(int i = 0, tmp = 1; i < nums.size(); tmp*=nums[i++])
            ans.push_back(tmp);
        for(int i = nums.size()-1, tmp = 1; i >= 0; tmp*=nums[i--])
            ans[i] *= tmp;
        
        return ans;
    }
};