class Solution {
public:
    bool isUgly(int num) {
        
        while(num)
        {
            if(num == 1)
                return true;
            if(num % 2 == 0)
                num /= 2;
            if(num % 3 == 0)
                num /= 3;
            if(num % 5 == 0)
                num /= 5;
            if(num!=1 && num%2 && num%3 && num%5)
                return false;
        }
        
        return false;
        /*
        if(num == 0)
            return false;
        else if(num == 1)
            return true;
        else if(num%2 == 0)
            return isUgly(num/2);
        else if(num%3 == 0)
            return isUgly(num/3);
        else if(num%5 == 0)
            return isUgly(num/5);
        return false;*/
    }
};