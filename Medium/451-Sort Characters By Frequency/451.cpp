class Solution {
public:
    string frequencySort(string s) {
        
        map<char, int> freq;
        for(int i = 0; i < s.size(); ++i)
            ++freq[s[i]];
        
        vector<pair<char, int>> vec(freq.begin(), freq.end());
        sort(vec.begin(), vec.end(), SortByValue());
        
        string ans = "";
        for(int i = 0; i < vec.size(); ++i)
            for(int j = 0; j < vec[i].second; ++j)
                ans += vec[i].first;
        
        return ans;
    }

static bool sortByValue(const pair<char, int> &lhs, const pair<char, int> &rhs){
    return lhs.second > rhs.second;
}
    
struct SortByValue{
    bool operator()(const pair<char, int> &lhs, const pair<char, int> &rhs){
        return lhs.second > rhs.second;
    }
};

};