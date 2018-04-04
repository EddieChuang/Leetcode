class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        int day = 60 * 24;
        bool *points = new bool[day * 2];
        for(int i = 0; i < day*2; ++i)
            points[i] = false;
        for(int i = 0; i < timePoints.size(); ++i){
            
            int hour = stoi(timePoints[i].substr(0, 2));
            int min  = stoi(timePoints[i].substr(3, 2));
            int p    = hour*60 + min;
            if(points[p])
                return 0;
            points[p] = points[p + day] = true;
        }
        
        int prev = -(12 * 60);
        int diff = INT_MAX;
        for(int i = 0; i < day * 2; ++i){
            if(points[i]){
                diff = min(diff, i-prev);
                prev = i;
            }
        }
        return diff;
    }
    
    
    
};