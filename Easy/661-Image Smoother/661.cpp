class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        
        vector<vector<int>> matrix(M.size(), (vector<int>(M[0].size(), 0)));
        for(int i = 0; i < M.size(); ++i)
            for(int j = 0; j < M[i].size(); ++j)
            {
                int num = 0, n = 0;
                for(int r = -1; r <= 1; ++r)
                    for(int c = -1; c <= 1; ++c)
                        if((i+r>=0 && i+r < M.size() && j+c >=0 && j+c < M[i].size()))
                        {
                            num += M[i+r][j+c];
                            n++;
                        }
                matrix[i][j] = num / n;
            }
        
        return matrix;
    }
};

