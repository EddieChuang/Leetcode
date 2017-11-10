class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        
        int n = 1;
        //candies = quickSort(candies);
        sort(candies.begin(), candies.end());
        for(int i = 0; i < candies.size() - 1 && n != candies.size()/2; ++i)
            if(candies[i] != candies[i+1])
                n++;
        return n;
    }
    
    
    vector<int> quickSort(vector<int> candies)
    {
        if(candies.size() <= 1)
            return candies;
        
        vector<int> less, greater;
        int index = rand() % candies.size();
        int pivot = candies[index];
        
        for(int i = 0; i < candies.size(); ++i)
        {
            if(pivot <= candies[i] && i != index)
                less.push_back(candies[i]);
            else if(pivot > candies[i])
                greater.push_back(candies[i]);
        }
        
        less = quickSort(less);
        less.push_back(pivot);
        greater = quickSort(greater);
        
        for(int i = 0; i < greater.size(); ++i)
            less.push_back(greater[i]);
        
        return less;
    }    
};