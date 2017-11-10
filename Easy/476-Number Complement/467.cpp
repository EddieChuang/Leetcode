class Solution {
public:
    int findComplement(int num) {
        
        int x = 1, complement = 0;
        for( ; num; num/=2, x*=2)
            complement += (1 - num % 2) * x;

        return complement;
    }
};