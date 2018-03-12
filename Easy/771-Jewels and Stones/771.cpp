class Solution {
public:
    int numJewelsInStones(string J, string S) {
        
        int num = 0;
        for(auto s : S)
            num = (J.find(s) != string::npos) ? num+1 : num;
        return num;
    }
};