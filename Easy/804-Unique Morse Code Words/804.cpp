class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        char table[26][10] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> morse;
        for(int i = 0; i < words.size(); ++i){
            string word = words[i];
            string code = "";
            for(int j = 0; j < word.size(); ++j){
                code += table[word[j] - 'a'];
            }
            morse.insert(code);
        }
        return morse.size();
    }
};