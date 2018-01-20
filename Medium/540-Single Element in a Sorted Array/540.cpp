class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        if(nums.size() == 3){
            if(nums[0] != nums[1])
                return nums[0];
            else
                return nums[2];
        }
        
        int mid = nums.size() / 2;
        vector<int> sub;
        if(mid % 2 == 0){
            if(nums[mid]==nums[mid-1])
                sub.assign(nums.begin(), nums.begin()+mid+1);
            else
                sub.assign(nums.begin()+mid, nums.end());
        }
        else{
            if(nums[mid]==nums[mid-1])
                sub.assign(nums.begin()+mid+1, nums.end());
            else
                sub.assign(nums.begin(), nums.begin()+mid);        
        }
        
        return singleNonDuplicate(sub);
    }
};