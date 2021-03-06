class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        vector<int> left(50000, -1), right(50000, -1), degree(50000, 0);
        int len = 99999, max_degree = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(left[nums[i]] == -1)
                left[nums[i]] = i;
            right[nums[i]] = i;
            degree[nums[i]]++;
        }
        
        for(int i = 0; i < left.size(); ++i)
        {
            if(left[i] == -1)
                continue;
            if(degree[i] >= max_degree)
            {
                if(degree[i] > max_degree)
                    len = right[i] - left[i] +1;
                else if(right[i] - left[i] + 1 < len)
                    len = right[i] - left[i] +1;
                max_degree = degree[i];
            }
        }
        return len;
    }
};