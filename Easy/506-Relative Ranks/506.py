class Solution(object):
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        
        sorted_nums = sorted(nums, reverse=True)
        ranks = {}
        for i in range(0, len(sorted_nums)):
            if i == 0:
                ranks[sorted_nums[i]] = "Gold Medal"
            elif i == 1:
                ranks[sorted_nums[i]] = "Silver Medal"
            elif i == 2:
                ranks[sorted_nums[i]] = "Bronze Medal"
            else:
                ranks[sorted_nums[i]] = str(i+1)
        
        return [ranks[n] for n in nums]