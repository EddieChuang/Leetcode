class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        
        ransom_set, magazine_set = {}, {}
        for c in ransomNote:
            ransom_set[c] = ransom_set.get(c, 0) + 1
        for c in magazine:
            magazine_set[c] = magazine_set.get(c, 0) + 1
        
        for key in ransom_set:
            
            if key not in magazine_set:
                return False
            if ransom_set[key] > magazine_set[key]:
                return False
        return True