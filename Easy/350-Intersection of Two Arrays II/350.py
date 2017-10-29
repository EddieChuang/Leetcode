class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """

        dict1 = {}
        for n in nums1:
            dict1[n] = dict1.get(n, 0) + 1
        
        intersection = []
        for n in nums2:
            if n in dict1 and dict1[n] > 0:
                intersection.append(n)
                dict1[n] -= 1
        
        return intersection