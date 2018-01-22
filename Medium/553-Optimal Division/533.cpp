class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        
        if(nums.size() == 1)
            return to_string(nums[0]);
        else if(nums.size() == 2)
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        
        
        string res = to_string(nums[0]) + "/(" + to_string(nums[1]);
        for(int i = 2; i < nums.size(); ++i)
            res += "/" + to_string(nums[i]);
        res += ")";
        
        return res;
    }
};