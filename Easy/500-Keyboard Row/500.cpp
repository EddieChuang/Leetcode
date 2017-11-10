class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        vector<string> row = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        int table[26];
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < row[i].size(); ++j)
                table[row[i][j] - 'a'] = i;
        
        
        vector<string> ans;
        for(int i = 0; i < words.size(); ++i)
        {
            int j;
            for(j = 0; j < words[i].size() - 1; ++j)
                if(table[tolower(words[i][j]) - 'a'] != table[tolower(words[i][j + 1]) - 'a'])
                    break;
            if(j == words[i].size() - 1)
                ans.push_back(words[i]);
        }
        return ans;        
    }
};