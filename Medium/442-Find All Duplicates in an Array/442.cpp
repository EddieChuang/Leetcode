class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> vec;
        int *count = new int[nums.size()+1];
        for(int i = 0; i <= nums.size(); ++i)
            count[i] = 0;
        for(int i = 0; i < nums.size(); ++i){
            ++count[nums[i]];
            if(count[nums[i]] > 1)
                vec.push_back(nums[i]);
        }
        return vec;
        
    }
};