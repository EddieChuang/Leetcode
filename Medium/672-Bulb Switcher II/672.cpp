class Solution {
public:
    
/*     struct Status{
        
        int num;
        bool* bulb;
        
        Status(int n){
            num = n;
            bulb = new bool[n];
            while(--n)
                bulb[n] = true;
        }
        
    };

    struct CustomCompare{
        bool operator()(const Status& lhs, const Status& rhs)
        {
            return lhs < rhs;
        }

        bool operator()(const Status& lhs, const Status& rhs){
            for(int i = 0; i < lhs.num; ++i)
                if(lhs.bulb[i] != rhs.bulb[i])
                    return true;
            return false;
        }
    };
    */
    int flipLights(int n, int m) {
        
         n = min(n, 3);
        if (m == 0) 
            return 1;
        if (m == 1) 
            return n == 1 ? 2 : n == 2 ? 3 : 4;
        if (m == 2) 
            return n == 1 ? 2 : n == 2 ? 4 : 7;
        
        return n == 1 ? 2 : n == 2 ? 4 : 8;
    }
    
    /*
    void backtracking(int n, int m, Status status){
        
        if(m == 0)
            return;
        
        // ALL
        Status nextStatus = flipAll(status, n);
        if(statusSet.find(nextStatus) == statusSet.end())
            statusSet.insert(nextStatus);
        backtracking(n, m-1, nextStatus);
        
        // EVEN
        nextStatus = flipEven(status, n);
        if(statusSet.find(nextStatus) == statusSet.end())
            statusSet.insert(nextStatus);
        backtracking(n, m-1, nextStatus);
        
        // ODD
        nextStatus = flipOdd(status, n);
        if(statusSet.find(nextStatus) == statusSet.end())
            statusSet.insert(nextStatus); 
        backtracking(n, m-1, nextStatus);
        
        // 3K+1
        nextStatus = flip3K(status, n);
        if(statusSet.find(nextStatus) == statusSet.end())
            statusSet.insert(nextStatus); 
        backtracking(n, m-1, nextStatus);
            
    }
    
    Status flipAll(Status status, int n){
        
        for(int i = 0; i < n; ++i)
            status.bulb[i] = !status.bulb[i];
        return status;
    }
    
    Status flipEven(Status status, int n){
        
        for(int i = 0; i < n; i += 2)
            status.bulb[i] = !status.bulb[i];
        return status;
    }
    
    Status flipOdd(Status status, int n){
        
        for(int i = 1; i < n; i += 2)
            status.bulb[i] = !status.bulb[i];
        return status;
    }
    
    Status flip3K(Status status, int n){
        
        for(int i = 0; 3*i+1 < n; ++i)
            status.bulb[3*i+1] = !status.bulb[3*i+1];
        return status;
    }

    set<Status, CustomCompare> statusSet;*/

};