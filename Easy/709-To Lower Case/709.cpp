class Solution {
public:
    string toLowerCase(string str) {
        
        int offset = 'a' - 'A';
        for(int i = 0; i < str.size(); ++i){
            if(str[i] >= 'A' && str[i] <= 'Z'){
                str[i] = str[i] + offset;
            }
        }
        return str;
    }
};