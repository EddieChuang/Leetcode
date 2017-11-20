class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string sum = "";
        int carry = 0;
        for(int i = num1.size()-1, j = num2.size()-1; i >= 0 || j >= 0 || carry; )
        {
            int s1 = i >= 0 ? num1[i--]-'0' : 0;
            int s2 = j >= 0 ? num2[j--]-'0' : 0;
            
            int s = s1 + s2 + carry;
            carry = s / 10;
            s %= 10;
            sum.insert(0, to_string(s));
        }
        return sum;
        
    }
};