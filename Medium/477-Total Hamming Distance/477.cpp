class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        
        int totalDistance = 0;
        for(int i = 0; i < nums.size(); ++i){
            int x = nums[i];
            for(int j = i+1; j < nums.size(); ++j)
                totalDistance += getHammingDistance(x, nums[j]);
        }
        return totalDistance;
        
    }
    
    int getHammingDistance(int x, int y){
        
        
        int distance = 0;
        while(x || y){
            
            distance += (x % 2) ^ (y % 2);
            x /= 2;
            y /= 2;
        }
        return distance; 
    }
};