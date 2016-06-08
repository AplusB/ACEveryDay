class Solution:
    """
    @param A : An integer array
    @return : Two integer
    """
    def singleNumberIII(self, A):
        exor = 0
        for i in A:
            exor ^= i

        pin = exor - (exor & (exor - 1))

        x1, x2 = 0, 0
        for i in A:
            if pin & i == 0:
                x1 ^= i
            else:
                x2 ^= i

        return (x1, x2)
