class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        if(magazine.size() < ransomNote.size())
            return false;
        
        mergeSort(ransomNote, 0, ransomNote.size() - 1);
        mergeSort(magazine, 0, magazine.size() - 1);

        int pos = 0;
        for(int i = 0; i < ransomNote.size(); ++i)
        {
            pos = binary_search(magazine, pos, magazine.size(), ransomNote[i]) + 1;
            if(ransomNote[i] != magazine[pos-1])
                return false;
        }
        return true;
    }
    
    int binary_search(string str, int x, int y, int c)
    {
        while(x < y)
        {
            int m = x + (y - x) / 2;
            if(str[m] >= c)
                y = m;
            else
                x = m + 1;
        }
        return x;
    }
    
    
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
        string left = str.substr(front, mid-front + 1);
        string right = str.substr(mid+1, end-mid);
        
        left += 'z' + 1;
        right += 'z' + 1;
        
        int idx_left = 0, idx_right = 0;
        for(int i = front; i <= end; ++i)
        {
            if(left[idx_left] < right[idx_right])
                str[i] = left[idx_left++];
            else
                str[i] = right[idx_right++];
        }
    }
    
};