class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        
        int x = (ops.size()) ? ops[0][0] : m;
        int y = (ops.size() && ops[0].size()) ? ops[0][1] : n;
        for(int i = 1; i < ops.size(); ++i)
        {
            if(ops[i][0] < x)
                x = ops[i][0];
            if(ops[i][1] < y)
                y = ops[i][1];
        }
        return x * y;
        
    }
};