class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i){
            vector<int>::iterator pos = find(ans.begin(), ans.end(), nums[i]);
            if(pos == ans.end())
                ans.push_back(nums[i]);
            else
                ans.erase(pos);
        }
        return ans;
    }
};