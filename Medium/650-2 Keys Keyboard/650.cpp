class Solution {
public:
    int minSteps(int n) {
        
        return n==1 ? 0 : helper(1, 1, n);
    }
    
    int helper(int nA, int copy, int n){
        
        
        if(nA == n)
            return 1;
        else if(nA > n)
            return 10000;
        
        int step1 = 10000, step2 = 10000, step3 = 10000;
        if(nA == copy) // last op is copy, now paste
            step1 = helper(nA+copy, copy, n);
        else { // copy or paste
            
            step2 = helper(nA, nA, n);        // copy
            step3 = helper(nA+copy, copy, n); // paste
        } 
        
        return min(step1, min(step2, step3)) + 1;
    }
};