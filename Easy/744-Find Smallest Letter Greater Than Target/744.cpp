class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        letters.push_back(target);
        sort(letters.begin(), letters.end());
        
        vector<char>::iterator it = find(letters.begin(), letters.end(), target);
        while(*(++it) == target)
            ;
        if(it == letters.end())
            return *letters.begin();
        else
            return *it;
        
    }
};