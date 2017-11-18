class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        map<char, string> m1;
        map<string, char> m2;
        string word;
        int i = 0;
        
        stringstream ss(str);
        while(ss >> word)
        {
            if(m1.find(pattern[i]) == m1.end() && m2.find(word) == m2.end())
            {
                m1[pattern[i]] = word;
                m2[word] = pattern[i];
            }
            else if(m1[pattern[i]] != word)
                return false;
            i++;
        }
        return i==pattern.size();
    }
};