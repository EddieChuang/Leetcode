class Solution {
public:
    vector<int> constructRectangle(int area) {
        
        int L, W;
        vector<int> ans{area, 1};
        for(int i = sqrt(area) + 1; i >= 1; --i)
        {
            if(area % i == 0)
            {
                L = area / i;
                W = i;
                if(ans[0] - ans[1] > L - W && L >= W)
                {
                    ans[0] = L;
                    ans[1] = W;
                }
            }
        }
        return ans;
    }
};