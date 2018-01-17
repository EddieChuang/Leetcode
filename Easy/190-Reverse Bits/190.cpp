class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        uint32_t reverse = 0;
        for(uint32_t x = 31; n > 0; --x, n /= 2)
            reverse += (n % 2) << x;
        return reverse;
    }
};