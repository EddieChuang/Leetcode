class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        
        
        //vector<int> sorted_nums = nums;
        //sort(sorted_nums.begin(), sorted_nums.end(), greater<int>());
        
        vector<int> sorted_nums = quickSort(nums);
        map<int, string> ranks;
        ranks[sorted_nums[0]] = "Gold Medal";
        ranks[sorted_nums[1]] = "Silver Medal";
        ranks[sorted_nums[2]] = "Bronze Medal";
        for(int i = 3; i < sorted_nums.size(); ++i)
            ranks[sorted_nums[i]] = to_string(i + 1);
        
        vector<string> ans;
        for(int i = 0; i < nums.size(); ++i)
            ans.push_back(ranks[nums[i]]);
        
        return ans;
    }
    
    vector<int> quickSort(vector<int> nums)
    {
        if(nums.size() <= 1)
            return nums;
        
        int index = rand() % nums.size();
        int pivot = nums[index];
        
        vector<int> less, greater;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] >= pivot && i != index)
                less.push_back(nums[i]);
            else if(nums[i] < pivot)
                greater.push_back(nums[i]);
        }
        
        less = quickSort(less);
        less.push_back(pivot);
        greater = quickSort(greater);
        
        for(int i = 0; i < greater.size(); ++i)
            less.push_back(greater[i]);
        
        return less;
    }
    
};
