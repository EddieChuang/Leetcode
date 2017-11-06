class Solution {
public:
    int countSegments(string s) {
        
        
        int len = 0;
        char *ptr = strtok(const_cast<char*>(s.c_str()), " ");
        for(; ptr != NULL; len++)
            ptr = strtok(NULL, " ");
        
        /* stringstream 
        stringstream ss(s);
        int len = 0;
        while(ss >> s)
            len++;
        */
        
        return len;
    }
};