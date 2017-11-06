class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<vector<int>> pascal;
        pascal.push_back(vector<int>(1, 1));
        for(int i = 1; i <= rowIndex; ++i)
        {
            vector<int> row(1, 1);
            for(int j = 1; j < i; ++j)
                row.push_back(pascal[i-1][j-1] + pascal[i-1][j]);
            row.push_back(1);
            pascal.push_back(row);
        }
        return pascal[rowIndex];
    }
};