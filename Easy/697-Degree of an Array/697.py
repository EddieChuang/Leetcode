class Solution:
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        left, right, degree = {}, {}, {}
        length, max_degree = 99999, 0
        for i in range(0, len(nums)):
            if nums[i] not in left:
                left[nums[i]] = i
            right[nums[i]] = i
            degree[nums[i]] = degree.get(nums[i], 0) + 1
        
        for key in left:
            if degree[key] >= max_degree:
                if degree[key] > max_degree:
                    length = right[key] - left[key] + 1
                elif right[key] - left[key] + 1 < length:
                    length = right[key] - left[key] + 1
                max_degree = degree[key]
        
        return length        