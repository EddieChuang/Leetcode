class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        if(nums.size() <= 1)
            return 0;
        
        map<int, int> count;
        for(int i = 0; i < nums.size(); ++i)
            count[nums[i]]++;
        
        int max_len = 0;
        for(map<int, int>::iterator it=count.begin(), it_next=++count.begin(); it_next!=count.end(); it++, it_next++)
            if(it->first + 1 == it_next->first && it->second + it_next->second > max_len)
                max_len = it->second + it_next->second;
        return max_len;
    }
};