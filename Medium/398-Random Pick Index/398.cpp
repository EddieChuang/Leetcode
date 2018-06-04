class Solution {
public:
    Solution(vector<int> nums_) {
        
       nums = nums_;
        
    }
    
    int pick(int target) {
        
        int pos = -1;
        int n   = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(pos == -1 && nums[i] != target)
                continue;
            else if(nums[i] != target)
                break;
            
            if(n == 0)
                pos = i;
            ++n;
        }
        return pos + rand() % n;
    }
    vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */