class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        mergeSort(g, 0, g.size() - 1);
        mergeSort(s, 0, s.size() - 1);
        
        int count = 0;
        for(int i = 0, j = 0; i < s.size() && j < g.size(); ++i)
        {
            if(s[i] >= g[j])
            {
                count++;
                j++;
            }
        }
        return count;
    }
    
    void mergeSort(vector<int> &vec, int front, int end)
    {
        if(front < end)
        {
            int mid = (front + end) / 2;
            mergeSort(vec, front, mid);
            mergeSort(vec, mid+1, end);
            merge(vec, front, mid, end);
        }
    }
    
    void merge(vector<int> &vec, int front, int mid, int end)
    {
        vector<int> left(vec.begin() + front, vec.begin() + mid + 1);
        vector<int> right(vec.begin() + mid + 1, vec.begin() + end + 1);
        
        left.push_back(2147483647);
        right.push_back(2147483647);
        
        int idx_left = 0, idx_right = 0;
        for(int i = front; i <= end; ++i)
        {
            if(left[idx_left] < right[idx_right])
                vec[i] = left[idx_left++];
            else
                vec[i] = right[idx_right++];
        }
        
    }
    
};