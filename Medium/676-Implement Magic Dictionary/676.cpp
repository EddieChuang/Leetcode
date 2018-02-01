class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        magicDict.clear();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto word : dict)
            magicDict.push_back(word);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        
        for(int i = 0, count = 0; i < magicDict.size(); ++i, count=0){
            if(magicDict[i].size() == word.size()){
                for(int j = 0; j < word.size(); ++j)
                    count = magicDict[i][j]==word[j] ? count : count+1;
                if(count == 1)
                    return true;
            }
        }
        return false;
    }
    
    vector<string> magicDict;
    
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */