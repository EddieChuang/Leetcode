class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        string max1 = "", max2 = "", max3 = "";
        for(int i = 0; i < nums.size(); ++i)
        {
            if((max1 != "" && nums[i] == stoi(max1)) || (max2 != "" && nums[i] == stoi(max2)) || (max3 != "" && nums[i] == stoi(max3)))
                continue;
            
            if(max1 == "" || nums[i] > stoi(max1))
            {
                max3 = max2;
                max2 = max1;
                max1 = to_string(nums[i]);
            }
            else if(max2 == "" || nums[i] > stoi(max2))
            {
                max3 = max2;
                max2 = to_string(nums[i]);
            }
            else if(max3 == "" || nums[i] > stoi(max3))
                max3 = to_string(nums[i]);
        }
        return max3=="" ? stoi(max1) : stoi(max3);
    }
};