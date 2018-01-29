class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        if(timeSeries.size() == 0)
            return 0;
        
        int total = duration;
        for(int i = 1; i < timeSeries.size(); ++i){
            if(timeSeries[i] - timeSeries[i-1] < duration)
                total += (timeSeries[i] - timeSeries[i-1]);
            else
                total += duration;
        }
        return total;
    }
};