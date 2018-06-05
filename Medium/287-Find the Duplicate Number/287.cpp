class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // Find the intersection point of the two runners.
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        
        // Find the "entrance" to the cycle.
        int runner = nums[0];
        while(runner != slow){
            runner = nums[runner];
            slow   = nums[slow];
        }
        return runner;
    }
};