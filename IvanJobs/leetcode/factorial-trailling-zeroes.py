class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 0:
            return 0
        res = 0
        while n != 0:
            n /= 5
            res += n
            
        return res
