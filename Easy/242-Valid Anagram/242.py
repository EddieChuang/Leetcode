class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        if len(s) != len(t):
            return False
        elif len(s) == 0 and len(t) == 0:
            return True
        
        table = {}
        for i in range(0, len(s)):
            table[s[i]] = table.get(s[i], 0) + 1
            table[t[i]] = table.get(t[i], 0) - 1
        
        for letter in table:
            if table[letter] != 0:
                return False
        return True
        