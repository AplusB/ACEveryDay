class Solution:
    """
    @param A : an integer array
    @return : a integer
    """
    def singleNumber(self, A):
        # write your code here
        if len(A) == 0:
            return 0
        res = A[0]
        la = len(A)
        for i in range(1, la):
            res ^= A[i]
            
        return res
