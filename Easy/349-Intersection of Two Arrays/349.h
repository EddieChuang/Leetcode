class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> intersection;
        set<int> set1, set2;
        if(nums1.empty() || nums2.empty())
            return intersection;
        
        mergeSort(nums1, 0, nums1.size() - 1);
        mergeSort(nums2, 0, nums2.size() - 1);
        
        for(int i = 0; i < nums1.size(); ++i)
            set1.insert(nums1[i]);
        for(int i = 0; i < nums2.size(); ++i)
            set2.insert(nums2[i]);
        
        for(set<int>::iterator it1=set1.begin(), it2=set2.begin(); it1 != set1.end() && it2 != set2.end() ;)
        {
            if(*it1 == *it2)
            {    
                intersection.push_back(*it1);
                it1++;
                it2++;
            }
            else if(*it1 > *it2)
                it2++;
            else if(*it1 < *it2)
                it1++;
        }
        return intersection;
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
        int idx_left = 0, idx_right = 0;
        left.push_back(999999);
        right.push_back(999999);
        for(int i = front; i <= end; ++i)
        {
            if(left[idx_left] < right[idx_right])
                vec[i] = left[idx_left++];
            else
                vec[i] = right[idx_right++];
        }
    }
};