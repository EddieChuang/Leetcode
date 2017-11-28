class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        for(int i = 0; i < flowerbed.size() && n; ++i)
        {
            int prev = i==0 ? 0 : flowerbed[i-1];
            int next = i==flowerbed.size()-1 ? 0 : flowerbed[i+1]; 
            if(!flowerbed[i] && !prev && !next)
            {                
                flowerbed[i] = 1;
                --n;
            }
        }
        return n == 0;
    }
};