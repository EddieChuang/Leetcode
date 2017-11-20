class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string sum = "0";
        //num1 = "18582506933032752";
        //num2 = "366213329703";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i = 0; i < num1.size() || i < num2.size(); ++i)
        {
            int s;
            if(i < num1.size() && i < num2.size())
                s = num1[i] + num2[i] - '0' - '0';
            else if(i < num1.size())
                s = num1[i] - '0';
            else if(i < num2.size())
                s = num2[i] - '0';
            
            s += sum[i]-'0';
            if(s >= 10)
                sum += "1";
            else
                sum += "0";
            sum[i] = s % 10 + '0';
        }
        if(sum[sum.size() - 1] == '0')
            sum = sum.substr(0, sum.size()-1);
        reverse(sum.begin(), sum.end());
        return sum;
        
    }
};