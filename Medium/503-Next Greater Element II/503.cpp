class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            res.push_back(nextGreater(nums, i));
        }
        return res;
    }
    
    int nextGreater(vector<int> nums, int index){
        
        int size = nums.size();
        int num  = nums[index];
        int greater = nums[index];
        for(int i = (index + 1) % size; i != index && greater == num; i = (i + 1) % size){
            greater = max(greater, nums[i]);
        }
        return greater == num ? -1 : greater;
    }
    
};