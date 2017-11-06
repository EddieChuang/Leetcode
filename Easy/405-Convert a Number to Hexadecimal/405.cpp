class Solution {
public:
    string toHex(int num) {
        
        char dec_hex[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                            '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        
        long n = num;
        if(n < 0)
            n += pow(2, 32);
        
        string hex = "";
        for( ; n != 0; n /= 16)
            hex.insert(0, string(1, dec_hex[n % 16]));
        
        return hex=="" ? "0" : hex;
    }
};