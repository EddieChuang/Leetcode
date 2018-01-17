class Solution {
    
    private:
        int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int visit[100][100] = {0};
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        DFS(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    
    void DFS(vector<vector<int>> &image, int sr, int sc, int color, int newColor)
    {
        int width  = image[0].size();
        int height = image.size();
        visit[sr][sc] = 1;
        image[sr][sc] = newColor;
        for(int i = 0; i < 4; ++i){
            int newSr = sr + direction[i][0];
            int newSc = sc + direction[i][1];
            cout << newSr << " " << newSc << endl;
            if(newSr >= 0 && newSr < height && newSc >= 0 && newSc < width &&
               image[newSr][newSc]==color && visit[newSr][newSc]==0)
                DFS(image, newSr, newSc, color, newColor);
            
        }
    }
    
};