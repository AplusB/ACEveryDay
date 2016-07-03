import math
class Solution:
    # @param n: an integer
    # @return an integer f(n)
    def fibonacci(self, n):
        # write your code here
        n -= 1
        r5 = math.sqrt(5)
        r5add = (1 + r5)/2
        r5minus = (1 - r5)/2
        
        
        res = (r5add**n - r5minus**n) / r5
        
        return int(res)
