bool sortByFirst(const pair<string, int> &lhs, const pair<string, int> &rhs){
        return lhs.first < rhs.first;
}

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        vector<pair<string, int>> sorted_list1, sorted_list2;
        for(int i = 0; i < list1.size(); ++i)
            sorted_list1.push_back({list1[i], i});
        for(int i = 0; i < list2.size(); ++i)
            sorted_list2.push_back({list2[i], i});

        sort(sorted_list1.begin(), sorted_list1.end(), sortByFirst);
        sort(sorted_list2.begin(), sorted_list2.end(), sortByFirst);

        vector<string> ans;
        int least = 3000;
        for(int i = 0, j = 0; i < sorted_list1.size() && j < sorted_list2.size();)
        {
            if(sorted_list1[i].first == sorted_list2[j].first)
            {
                int index = sorted_list1[i].second + sorted_list2[j].second;
                if(index < least)
                {
                    ans.clear();
                    ans.push_back(sorted_list1[i].first);
                    least = index;
                }
                else if(index == least)
                    ans.push_back(sorted_list1[i].first);
                i++;
                j++;
            }
            else if(sorted_list1[i].first < sorted_list2[j].first)
                i++;
            else
                j++;
        }
        return ans;
        
    }
    /*
    int binary_search(vector<pair<string, int>> list, string target)
    {
        int x = 0, y = list.size();
        while(x < y)
        {
            int m = (x + y) / 2;
            if(target > list[m].first)
                x = m + 1;
            else if(target < list[m].first)
                y = m;
            else
                return list[m].second;
        }
        return -1;
    }
    
    vector<string> quickSort(vector<string> list)
    {
        if(list.size() <= 1)
            return list;
        
        int index = rand() % list.size();
        string pivot = list[index];
        
        vector<string> less, greater;
        for(int i = 0; i < list.size(); ++i)
        {
            if(list[i] < pivot)
                less.push_back(list[i]);
            else if(list[i] > pivot)
                greater.push_back(list[i]);
        }
        
        less = quickSort(less);
        less.push_back(pivot);
        greater = quickSort(greater);
        
        for(int i = 0; i < greater.size(); ++i)
            less.push_back(greater[i]);
        return less;
    }
    */
};