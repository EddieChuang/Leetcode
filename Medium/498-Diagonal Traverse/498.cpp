class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;
        if(matrix.size() == 0)
            return ans;
        
        int flag = 0, i = 0, j = 0;
        int m = matrix.size(), n = matrix[0].size();
        int dire[2][2] = { {-1, 1}, {1, -1} }; 
        
        while(ans.size() < m * n){
            
            ans.push_back(matrix[i][j]);
            i += dire[flag][0];
            j += dire[flag][1];
            
            if(i >= m){
                i = m-1; j += 2;
                flag = flag ? 0 : 1;
            }
            if(j >= n){
                i += 2; j = n - 1;
                flag = flag ? 0 : 1;
            }
            if(i < 0){
                i = 0;
                flag = flag ? 0 : 1;
            }
            if(j < 0){
                j = 0;
                flag = flag ? 0 : 1;
            }
        }

        return ans;
    }
};