class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int maxProduct = 0;
        for(int i = 0; i < words.size(); ++i){
            for(int j = i+1; j < words.size(); ++j){
                if(!hasCommonLetter(words[i], words[j])){
                    maxProduct = max(maxProduct, int(words[i].size()*words[j].size()));
                }
            }
        }
        return maxProduct;
    }
    
    bool hasCommonLetter(string str1, string str2){
        
        for(auto c : str1){
            if(str2.find(c) != string::npos)
                return true;
        }
        return false;
    }
    
};