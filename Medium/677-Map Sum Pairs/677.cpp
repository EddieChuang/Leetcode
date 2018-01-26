class MapSum {
public:
    
    typedef pair<string, int> PAIR;
    
    /** Initialize your data structure here. */
    MapSum() {

    }
    
    void insert(string key, int val) {
        
        PAIR data(key, val);
        vector<PAIR>::iterator iter = find_if(map.begin(), map.end(), bind(compare, std::placeholders::_1, key));
        if(iter == map.end())
            map.push_back(data);
        else
            iter->second = data.second;
    }
    
    int sum(string prefix) {
        
        int sum = 0;
        for(vector<PAIR>::iterator it = map.begin(); it != map.end(); ++it)
            if(it->first.find(prefix) == 0)
                sum += it->second;
        
        return sum;
    }
    

    static bool compare(PAIR& obj, string key)
    {
        return obj.first == key;
    }
    
private:
    vector<PAIR> map;

};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */