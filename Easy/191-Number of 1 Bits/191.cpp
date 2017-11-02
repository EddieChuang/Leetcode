class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int weight = 0;
        while(n)
        {
            weight += n % 2;
            n /= 2;
        }
        return weight;
    }
};