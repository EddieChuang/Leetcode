class Solution {
public:
    int countSubstrings(string s) {
        
        int count = 0;
        for(int i = 0; i < s.size()*2 - 1; ++i){
            int left = i / 2, right = left + i%2;
            while(left >= 0 && right < s.size() && s[left--]==s[right++])
                ++count;
        }
        return count;
    }
};