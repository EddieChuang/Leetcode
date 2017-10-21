class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        ans, x = 0, 26**(len(s)-1)
        for c in s:
            ans += (ord(c)-64) * x
            x /= 26
        return ans  