class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        
        vector<int> sorted = vector<int>(A.size());
        int evenIdx = 0;
        int oddIdx = A.size() - 1;
        for(int i = 0; i < A.size(); ++i){
            if(A[i] % 2 == 0){
                sorted[evenIdx++] = A[i];
            } else {
                sorted[oddIdx--] = A[i];
            }
        }
        return sorted;
    }
};