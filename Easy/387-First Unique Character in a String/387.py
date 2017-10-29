class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        letter = set();
        for i, c in enumerate(s):
            if c not in letter and s.count(c) == 1:
                return i
            else:
                letter.add(c)
        return -1