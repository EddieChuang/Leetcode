class Solution {
public:
    int reverse(int x) {

        long reverseX = 0;
        while(x){
            reverseX = (x % 10) + reverseX * 10;
            x /= 10;
        }    
        if(reverseX >= numeric_limits<int>::max() || reverseX <= numeric_limits<int>::min())
            return 0;
        
        return reverseX;
    }
};

/*
static int x = []() { 
    std::ios::sync_with_stdio(false); 
    cin.tie(NULL);  
    return 0; 
}();*/
