class Solution {
public:
    string convertToBase7(int num) {
        
        if(num >= 0)
            return base7(num);
        else
            return "-" + base7(abs(num));   
    }
    
    string base7(int num)
    {
        if(num == 0)
            return "0";
        string base7_num = "";
        while(num)
        {
            
            base7_num += to_string(num % 7);
            num /= 7;
        }
        reverse(base7_num.begin(), base7_num.end());
        return base7_num;
    }
    
};