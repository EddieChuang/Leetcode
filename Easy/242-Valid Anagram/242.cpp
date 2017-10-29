class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() == 0 && t.size() == 0)
            return true;
        else if(s.size() != t.size())
            return false;
        
        map<int, int> count;
        for(int i = 0; i < s.size(); ++i)
        {
            count[s[i]]++;
            count[t[i]]--;
        }
        for(map<int, int>::iterator it = count.begin(); it != count.end(); it++)
            if(it->second != 0)
                return false;
        return true;
    }
    /*
    void mergeSort(string &str, int front, int end)
    {
        if(front < end)
        {
            int mid = (front + end) / 2;
            mergeSort(str, front, mid);
            mergeSort(str, mid+1, end);
            merge(str, front, mid, end);
        }
    }
    
    void merge(string &str, int front, int mid, int end)
    {
        string left  = str.substr(front, mid-front+1);
        string right = str.substr(mid+1, end-mid);
        
        left  += 'z'+1;
        right += 'z'+1;
        
        int idx_left = 0, idx_right = 0;
        for(int i = front; i <= end; ++i)
        {
            if(left[idx_left] < right[idx_right])
                str[i] = left[idx_left++];
            else
                str[i] = right[idx_right++];
        }
    }
    */
    
};