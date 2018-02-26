class Solution {
public:
    Solution(vector<int> nums) {
        origin = vec = nums;
        srand(time(NULL));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        vec = origin;
        return vec;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        
        for(int i = vec.size()-1; i > 0; --i){
            int index = rand() % (i+1);
            swap(vec[i], vec[index]);
        }
        
        return vec;
    }
    
private:
    
    vector<int> origin;
    vector<int> vec;
    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */