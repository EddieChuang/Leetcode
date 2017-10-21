class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        for(int i = 0; i < numbers.size(); ++i)
        {
            int diff = target - numbers[i];
            int index = binarySearch(numbers, diff, i);
            if(index != -1)
                return vector<int>{i+1, index+1};
        }
        
    }
    
    int binarySearch(vector<int> numbers, int target, int i)
    {
        int x = 0, y = numbers.size() - 1;
        while(x <= y)
        {
            int m = (x + y) / 2;
            if(target < numbers[m])
                y = m - 1;
            else if(target > numbers[m])
                x = m + 1;
            else if(m == i)
                return m + 1;
            else
                return m;
        }
        return -1;
    }
    
    /*int binary_search(vector<int> number, int target, int x, int y)
    {
        if(x > y)
            return -1;
        int m = (x + y) / 2;
        if(target < number[m])
            return binary_search(number, target, x, m - 1);
        else if(target > number[m])
            return binary_search(number, target, m + 1, y);
        else 
            return m;
    }
    */
    
};