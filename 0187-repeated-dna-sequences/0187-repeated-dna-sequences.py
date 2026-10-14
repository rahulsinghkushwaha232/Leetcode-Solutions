class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        seen = set()
        res = set()
        
        for i in range(len(s) - 9):
            substring = s[i:i + 10]
            if substring in seen:
                res.add(substring)
            else:
                seen.add(substring)
                
        return list(res)