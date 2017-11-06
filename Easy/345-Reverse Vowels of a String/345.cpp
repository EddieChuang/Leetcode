class Solution {
public:
    string reverseVowels(string s) {
        
        set<int> vowel;
        vowel.insert('a'); vowel.insert('e'); vowel.insert('i'); vowel.insert('o'); vowel.insert('u');
        vowel.insert('A'); vowel.insert('E'); vowel.insert('I'); vowel.insert('O'); vowel.insert('U');
        for(int i = 0, j = s.size()-1; i < j; )
        {
            if(vowel.find(s[i]) == vowel.end())
                i++;
            if(vowel.find(s[j]) == vowel.end())
                j--;
            if(vowel.find(s[i]) != vowel.end() && vowel.find(s[j]) != vowel.end())
                swap(s[i++], s[j--]);   
        }
        return s;
    }
};