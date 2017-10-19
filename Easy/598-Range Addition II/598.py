class Solution:
    def maxCount(self, m, n, ops):
        """
        :type m: int
        :type n: int
        :type ops: List[List[int]]
        :rtype: int
        """
        
        for op in ops:
            m = min(op[0], m)
            n = min(op[1], n)
        return n * m