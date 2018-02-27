class Solution {
public:
    int countPrimes(int n) {
        
        int count = 0;
        bool *isPrime = new bool[n];
        for(int i = 0; i < n; ++i)
            isPrime[i] = true;
        for(int i = 2; i < n; ++i){
            if(isPrime[i]){
                ++count;
                for(int j = 2; i * j < n; ++j)
                    isPrime[i * j] = false;
            }
        }
        return count;
    }
};