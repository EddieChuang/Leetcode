class Solution {
public:
    string originalDigits(string s) {
        
        bool stop = false;
        return greedy(s, stop);
    }
    
    string greedy(string str, bool &stop){
        
        if(str == ""){
            stop = true;
            return "";   
        } 
        
        for(int i = 0; i < 10; ++i){
            string digit = digits[i];
            if(contain(str, digit)){
                string ans = to_string(i);
                string removed = remove(str, digit);     
                string res = greedy(removed, stop);
                if(stop){
                    return ans + res;
                }
            }
        }
        
        return "";
    }
    
    bool contain(string str, string target){
        
        for(int i = 0; i < target.size(); ++i){
            int pos = str.find(target[i]);
            if(pos == string::npos){
                return false;
            }
            str.erase(pos, 1);
        }
        return true;
    }
    
    string remove(string str, string target){
        // cout << str << endl;
        for(int i = 0; i < target.size(); ++i){
            int pos = str.find(target[i]);
            str.erase(pos, 1);
        }
        // cout << endl;
        return str;
    }
    
    
    string digits[10] = 
			{"zero", "one", "two", "three", "four", 
			"five", "six", "seven", "eight", "nine"};

};