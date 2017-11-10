class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        
        
        int position[10000];
        for(int i = 0; i < nums.size(); ++i)
            position[nums[i]] = i;
        
        vector<int> nextGreater;
        for(int i = 0; i < findNums.size(); ++i)
        {
            for(int j = position[findNums[i]]+1; j < nums.size() && nextGreater.size() != i+1; ++j)
                if(findNums[i] < nums[j])
                    nextGreater.push_back(nums[j]);
            
            if(nextGreater.size() != i+1)
                nextGreater.push_back(-1);
        }
        return nextGreater;
    }
};