class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int Perimeter = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[i].size(); ++j)
            {
                if(grid[i][j] == 1)
                {
                    if(i == 0)
                        Perimeter++;
                    if(i == grid.size() - 1)
                        Perimeter++;
                    if(j == 0)
                        Perimeter++;
                    if(j == grid[i].size() - 1)
                        Perimeter++;
                    if(j < grid[i].size()-1 && grid[i][j+1] == 0)
                        Perimeter++;
                    if(j > 0 && grid[i][j-1] == 0)
                        Perimeter++;
                    if(i < grid.size()-1 && grid[i+1][j] == 0)
                        Perimeter++;
                    if(i > 0 && grid[i-1][j] == 0)
                        Perimeter++;
                }
                
                
            }
        }
        return Perimeter;
        
        
        
        
    }
};