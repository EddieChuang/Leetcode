class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        int count[100000] = {0};
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i)
            count[nums[i]]++;
        for(int i = 1; i <= nums.size(); ++i)
            if(count[i]==0)
                ans.push_back(i);
        return ans;
    }
};