class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        
        g = self.quickSort(g)
        s = self.quickSort(s)
        
        count, i = 0, 0
        
        for cookie in s:
            if cookie >= g[i]:
                i += 1
                count += 1
            if i >= len(g):
                break
        return count
        
        
    def quickSort(self, arr):
        
        if len(arr) <= 1:
            return arr
        
        index = random.randint(0, len(arr) - 1)
        pivot = arr[index]
        
        less, greater = [], []
        for i in range(0, len(arr)):
            if arr[i] <= pivot and index != i:
                less.append(arr[i])
            elif arr[i] > pivot:
                greater.append(arr[i])
        
        return self.quickSort(less) + [pivot] + self.quickSort(greater)