class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        
        return list(set(nums1) & set(nums2))
        
    def quicksort(self, arr):
        
        if len(arr) <= 1:
            return arr
        
        index = random.randint(0, len(arr)-1)
        pivot = arr[index]
        less, greater = [], []
        
        for i in range(0, len(arr)):
            if arr[i] <= pivot and i != index:
                less.append(arr[i])
            elif arr[i] > pivot:
                greater.append(arr[i])
        
        return self.quicksort(less) + [pivot] + self.quicksort(greater)  