class Solution {
public:
    int countArrangement(int N) {
        
        vector<int> vec;
        for(int i = 1; i <= N; ++i)
            vec.push_back(i);
        
        return constructArrangement(vec, 1);
    }

    int constructArrangement(vector<int> vec, int pos){
        
        if(vec.size() == 0)
            return 1;

        int count = 0;
        for(int i = 0; i < vec.size(); ++i){
            int val = vec[i];
            if(!(val%pos) || !(pos%val)){
                vec.erase(vec.begin() + i);
                count += constructArrangement(vec, pos+1);
                vec.insert(vec.begin()+i, val);
            }
        }
        return count;
    }
};