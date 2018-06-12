class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        
        if(points.size() == 0)
            return 0;
        
        sort(points.begin(), points.end(), compare);
        
        int pos = points[0].second;
        int count = 1;
        for(int i = 1; i < points.size(); ++i){
            count = pos < points[i].first ? count + 1 : count;
            pos   = pos < points[i].first ? points[i].second : pos;
        }
        return count;
    }
    
    static bool compare(const pair<int, int>& a, const pair<int, int>& b) {
      return a.second < b.second;

    }

};