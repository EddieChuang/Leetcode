class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        
        vector<string> vec(words);
        int match[1001] = {0};
        int max = 0;
        for(int i = 0; i < licensePlate.size(); ++i){
            for(int j = 0; j < vec.size(); ++j){
                size_t pos = vec[j].find(tolower(licensePlate[i]));
                if(pos != string::npos){
                    ++match[j];
                    vec[j][pos] = '#';
                }
                if(match[max] < match[j])
                    max = j;
                else if(match[max] == match[j] && vec[max].size() > vec[j].size())
                    max = j;
            }
        }

        return words[max];
    }
};