class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int> count;
        for(auto n : nums)
            ++count[n];
        
        vector<pair<int, int>> vec(count.begin(), count.end());
        sort(vec.begin(), vec.end(), SortByValue());
        
        vector<int> ans;
        for(int i = 0; i < k; ++i)
            ans.push_back(vec[i].first);
        return ans;
        
    }

struct SortByValue{
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs){
        return lhs.second > rhs.second;
    }
};
    
static bool sortByValue(const pair<int, int> &lhs, const pair<int, int> &rhs){
    return lhs.second > rhs.second;
}
    
};