class Solution:
    """
    @param a, b: Two integer
    return: An integer
    """
    def bitSwapRequired(self, a, b):
        if a < 0:
            a = 2**32 - abs(a)
        if b < 0:
            b = 2**32 - abs(b)
        # write your code here
        handle = a ^ b
        # count number of 1 in handle
        res = 0
        while handle != 0:
            res += 1
            handle = handle & (handle - 1)
            
        return res
