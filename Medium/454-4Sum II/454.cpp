class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        
        map<int, int> AB;
        for(int numA : A)
            for(int numB : B)
                ++AB[-(numA + numB)];
        
        int count = 0;
        for(int numC : C)
            for(int numD : D)
                count += AB[numC + numD]!=0 ? AB[numC + numD] : 0;
               
        return count;
        
    }
};