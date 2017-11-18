class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int distance = 0;
        for(; x || y; x/=2, y/=2)
            if(x % 2 != y % 2)
                distance++;
        
        return distance;
    }
};