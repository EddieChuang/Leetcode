class Solution {
public:
    bool isHappy(int n) {
        
        set<int> exist;
        do
        {
            exist.insert(n);
            n = calculate(n);
        }while(n != 1 && exist.find(n) == exist.end());
        return n == 1;
    }
    
    int calculate(int n)
    {
        int x = 0;
        for( ; n != 0; n /= 10)
            x += pow((n % 10), 2);
        return x;
    }
    
};