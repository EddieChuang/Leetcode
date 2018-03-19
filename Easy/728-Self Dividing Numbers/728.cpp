class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        
        vector<int> ans;
        while(left <= right)
            selfDividing(ans, left++);
        return ans;
    }
    
    void selfDividing(vector<int> &ans, int number){
        
        int n = number;
        while(n){
            int d = n % 10;
            n /= 10;
            if(d == 0 || number % d != 0)
                return;
        }        
        ans.push_back(number);
    }
    
};