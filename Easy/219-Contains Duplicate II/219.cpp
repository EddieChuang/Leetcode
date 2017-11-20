class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        map<int, vector<int>> m;
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = 0; j < m[nums[i]].size(); ++j)
                if(i - m[nums[i]][j] <= k)
                    return true;
            m[nums[i]].push_back(i);
        }
        return false;
    }
};