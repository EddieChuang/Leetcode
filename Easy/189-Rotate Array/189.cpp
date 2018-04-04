class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        int* a = new int[n];
        for (int i = 0; i < n; i++) {
            a[(i + k) % n] = nums[i];
        }
        for (int i = 0; i < n; i++) {
            nums[i] = a[i];
        }
        
        
        
    }
};