class NumArray {
public:
    NumArray(vector<int> nums) {
        
        if(nums.empty())
            return ;
        
        cumulative_sum.push_back(nums[0]);
        for(int i = 1; i < nums.size(); ++i)
            cumulative_sum.push_back(cumulative_sum[i-1] + nums[i]);
    }
    
    int sumRange(int i, int j) {     
        return cumulative_sum[j] - cumulative_sum[i-1];
    }
    
private:
    
    vector<int> cumulative_sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */