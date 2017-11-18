class Solution {
public:
    string addBinary(string a, string b) {
        
        a.insert(0, "0");
        b.insert(0, "0");
        int carry = 0;
        string sum = "";
        for(int i = a.size()-1, j = b.size()-1; i > 0 || j > 0;)
        {
            string s = to_string((a[i] + b[j] + carry - '0'*2) % 2);
            sum.insert(0, s);
            carry = (a[i] + b[j] + carry - '0'*2) / 2;
            i = i - 1 > 0 ? i - 1: 0;
            j = j - 1 > 0 ? j - 1: 0;
        }
        if(carry)
            sum.insert(0, "1");
        return sum;
    }
};