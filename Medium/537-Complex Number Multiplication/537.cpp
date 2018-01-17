class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        
        int pos = a.find("+");
        int aReal = stoi(a.substr(0, pos));
        int aImg = stoi(a.substr(pos+1));
        
        pos = b.find("+");
        int bReal = stoi(b.substr(0, pos));
        int bImg = stoi(b.substr(pos+1));
        
        int real = aReal*bReal - aImg*bImg;
        int img  = aReal*bImg + aImg*bReal;
        return to_string(real) + "+" + to_string(img) + "i";
        
        
    }
};