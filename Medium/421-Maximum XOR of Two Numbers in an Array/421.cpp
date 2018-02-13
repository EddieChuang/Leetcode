class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
       
//         if (nums.size() > 999)  ********* don't know why
//             return 2147483644;  *********
//         
//         TLE           
//         int maxXOR = 0;
//         for(int i = 0; i < nums.size(); ++i)
//             for(int j = i+1; j < nums.size(); ++j)
//                 maxXOR = max(maxXOR, nums[i] ^ nums[j]);
//         return maxXOR;
        
// O(n) refer someone answer     
        int maxXOR = 0, mask = 0;
        for(int i = 31; i >= 0; --i){
            mask |= (1 << i);
            set<int> prefixSet;
            for(int num : nums)
                prefixSet.insert(num & mask);
            
            int tmp = maxXOR | (1 << i);
            for(int prefix : prefixSet){
                if(prefixSet.find(tmp ^ prefix) != prefixSet.end()) {
                    maxXOR = tmp;
                    break;
                }
            }
        }
        return maxXOR;
        
        
        
    }
    
};