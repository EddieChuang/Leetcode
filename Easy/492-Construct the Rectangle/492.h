//bool sortByValue(const pair<int, int> &lhs, const pair<int, int> &rhs)
//{
//    return lhs.second < rhs.second;
//}

class Solution {
public:
    vector<int> constructRectangle(int area) {
        
        map<int, int> m;
        for(int i = 1; i <= sqrt(area); ++i)//1 2
        {
            if(area % i != 0)
                continue;
            
            int quotient = area / i;
            m[quotient] = quotient - i;
        }
        vector<pair<int, int>> vec (m.begin(), m.end());
        mergeSort(vec, 0, vec.size() - 1);
        //sort(vec.begin(), vec.end(), sortByValue);
        return vector<int>{vec[0].first, area / vec[0].first};
    }
    
    void mergeSort(vector<pair<int, int>> &arr, int front, int end)
    {
        if(front < end)
        {
            int mid = (front + end) / 2;
            mergeSort(arr, front, mid);
            mergeSort(arr, mid + 1, end);
            merge(arr, front, mid, end);
            
        }
    }
    
    void merge(vector<pair<int, int>> &arr, int front, int mid, int end)
    {
        vector<pair<int, int>> left(arr.begin() + front, arr.begin() + mid + 1);
        vector<pair<int, int>> right(arr.begin() + mid + 1, arr.begin() + end + 1);
        
        int idx_left = 0, idx_right = 0;
        for(int i = front; i <= end; ++i)
        {
            if(left[idx_left].second < right[idx_right].second)
                arr[i] = left[idx_left++];
            else
                arr[i] = right[idx_right++];
        }
    }
};