class Solution {
public:
    int addDigits(int num) {
        
        if(num / 10 == 0)
            return num;
        
        int n = 0;
        while(num)
        {
            n += num % 10;
            num /= 10;
        }
        
        return addDigits(n);
    }
};