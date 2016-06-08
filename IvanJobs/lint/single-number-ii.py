class Solution:
    """
    @param A : An integer array
    @return : An integer
    """
    def singleNumberII(self, A):
        bitmap = [0] * 35

        for val in A:
            val = abs(val)
            tmp = bin(val)[2:]

            lt = len(tmp)
            i, j = lt - 1, 34
            while i >= 0:
                bitmap[j] += int(tmp[i])
                i -= 1
                j -= 1

        for i in range(35):
            bitmap[i] %= 3

        return int(''.join(map(str, bitmap)), 2)

