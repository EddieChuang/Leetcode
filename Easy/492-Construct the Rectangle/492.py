class Solution(object):
    def constructRectangle(self, area):
        """
        :type area: int
        :rtype: List[int]
        """
        
        diff = {}
        for i in range(1, int(math.sqrt(area)) + 1):
            
            if(area % i != 0):
                continue
            quotient = area / i;
            diff[quotient] = quotient - i;
        
        #sorted_diff = sorted(diff.items(), key=operator.itemgetter(1))
        sorted_diff = self.quickSort(diff.items())
        return [sorted_diff[0][0], area / sorted_diff[0][0]]
    
    def quickSort(self, arr):
        
        if len(arr) <= 1:
            return arr
        
        index = random.randint(0, len(arr) - 1)
        pivot = arr[index]
        
        less, greater = [], []
        for i in range(0, len(arr)):
            if arr[i][1] < pivot[1] and i != index:
                less.append(arr[i])
            elif arr[i][1] > pivot[1]:
                greater.append(arr[i])
        
        return self.quickSort(less) + [pivot] + self.quickSort(greater)