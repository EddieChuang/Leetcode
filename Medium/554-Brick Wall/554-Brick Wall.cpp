class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        int num = 0;
        int edge[1000000] = { 0 };
        for(int i = 0; i < wall.size(); ++i){
            for(int j=0, width=wall[i][j]; j < wall[i].size() - 1; ){

                num = max(num, ++edge[width]);
                width += wall[i][++j];
            }
        }
        
        return wall.size() - num;
    }
}