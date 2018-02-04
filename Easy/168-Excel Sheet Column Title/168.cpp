class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        char a = 'A'-1;
        while(n > 0){
            --n;
            char c = 'A' + n % 26;
            ans.insert(0, string(1, c));
            n /= 26;
        }
        return ans;
    }
};
