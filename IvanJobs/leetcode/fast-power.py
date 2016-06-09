class Solution:
    """
    @param a, b, n: 32bit integers
    @return: An integer
    """
    def fastPower(self, a, b, n):
        # write your code here
        if n == 0:
            return 1 % b
        else:
            tmp = self.fastPower(a, b, n/2)
            if n & 1:
                return (tmp * tmp * a) % b
            else:
                return (tmp * tmp) % b
                
