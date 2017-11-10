class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        
        if(r * c != nums.size() * nums[0].size())
            return nums;
        
        vector<vector<int>> reshaped(r, vector<int>());
        int row = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = 0; j < nums[i].size(); ++j)
            {
                reshaped[row].push_back(nums[i][j]);
                if(reshaped[row].size() == c)
                    row++;
            }
        }
        return reshaped;
    }
};