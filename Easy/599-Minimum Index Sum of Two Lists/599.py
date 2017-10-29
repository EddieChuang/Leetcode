class Solution:
    def findRestaurant(self, list1, list2):
        """
        :type list1: List[str]
        :type list2: List[str]
        :rtype: List[str]
        """
        
        dict1 = {list1[i]:i for i in range(0, len(list1))}
        
        least = 3000
        ans = []
        for i in range(0, len(list2)):
            
            if list2[i] in dict1:
                index = i + dict1[list2[i]]
                if index < least:
                    ans = []
                    ans.append(list2[i])
                    least = index
                elif index == least:
                    ans.append(list2[i])
        return ans