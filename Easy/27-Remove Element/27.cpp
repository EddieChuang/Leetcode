class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == val)
            {
                nums[i] = nums[nums.size()-1];
                nums.resize(nums.size()-1);
                --i;
            }
        }
        return nums.size();
    }
};