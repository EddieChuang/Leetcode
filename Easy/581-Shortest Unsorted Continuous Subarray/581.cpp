class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int> vec(nums);
        sort(vec.begin(), vec.end());
        
        int i = 0, j = nums.size() - 1;
        while((vec[i]==nums[i] || vec[j]==nums[j]) && i < j)
        {
            i = vec[i]==nums[i] ? i+1 : i;
            j = vec[j]==nums[j] ? j-1 : j;
        }
        return i==j ? 0 : j - i + 1;
    }
};