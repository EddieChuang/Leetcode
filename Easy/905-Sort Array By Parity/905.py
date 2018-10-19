class Solution:
    def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        
        sortedArr = [] * len(A)
        evenIdx = 0
        for number in A:
            if number % 2:
                sortedArr.append(number)
            else:
                sortedArr.insert(evenIdx, number)
                evenIdx += 1
        
        return sortedArr
        