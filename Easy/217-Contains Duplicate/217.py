class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        nums = self.quickSort(nums)
        for i in range(0, len(nums)-1):
            if nums[i] == nums[i+1]:
                return True
        return False
        
    def quickSort(self, nums):
        
        if len(nums) <= 1:
            return nums
        
        index = random.randint(0, len(nums)-1)
        pivot = nums[index]
        
        less, greater = [], []
        for i in range(0, len(nums)):
            if nums[i] <= pivot and i != index:
                less.append(nums[i])
            elif nums[i] > pivot:
                greater.append(nums[i])
        
        return self.quickSort(less) + [pivot] + self.quickSort(greater)