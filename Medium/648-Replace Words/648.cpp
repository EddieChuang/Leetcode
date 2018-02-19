class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        
        sort(dict.begin(), dict.end(), sortByLength);
        string ans = "", tmp;
        stringstream ss(sentence);
        while(ss >> tmp){
            for(int i = 0; i < dict.size(); ++i){
                if(tmp.find(dict[i]) == 0){
                    tmp = dict[i];
                    break;
                }
            }
            ans += " " + tmp;
        }
        return ans.substr(1, ans.size());
    }
    
    static bool sortByLength(const string &lhs, const string &rhs) { 
        return lhs.size() < rhs.size(); 
    }

};