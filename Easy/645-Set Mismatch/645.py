class Solution:
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        count = {}
        ans = [0]*2
        for n in nums:
            count[n] = count.get(n, 0) + 1
        for i in range(1, len(nums)+1):
            if i not in count:
                ans[1] = i
            elif count[i] == 2:
                ans[0] = i
        return ans        