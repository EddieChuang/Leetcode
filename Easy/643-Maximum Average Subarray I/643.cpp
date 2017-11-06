class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int size = nums.size();
        int *sum = new int[nums.size()];
        sum[0] = nums[0];
        for(int i = 1; i < size; ++i)
            sum[i] = nums[i] + sum[i-1];
        
        double max_sum = sum[k-1];
        for(int i = 0, j = k; j < size; ++i, ++j)
            max_sum = max(int(max_sum), sum[j]-sum[i]);
        return max_sum / k;
        
    }
};