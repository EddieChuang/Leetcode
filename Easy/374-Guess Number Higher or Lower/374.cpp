// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        
        int low = 1;
        while (low <= n) 
        {
            int mid = low + (n - low) / 2;
            int g = guess(mid);
            if (g == -1)
                n = mid - 1;
            else if (g == 1)
                low = mid + 1;
            else
                return mid;
        }
        
    }
};