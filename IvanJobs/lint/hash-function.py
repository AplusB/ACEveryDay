class Solution:
    
    def fastPower(self, n, HASH_SIZE):
        if n == 0:
            return 1 % HASH_SIZE
        else:
            tmp = self.fastPower(n/2, HASH_SIZE)
            if n & 1:
                return (tmp * tmp * 33) % HASH_SIZE
            else:
                return (tmp * tmp) % HASH_SIZE 
    """
    @param key: A String you should hash
    @param HASH_SIZE: An integer
    @return an integer
    """
    def hashCode(self, key, HASH_SIZE):
        # write your code here
        key = list(key)
        n = len(key)
        res = 0
        for i in range(n):
            cv = ord(key[i])
            res += cv * self.fastPower(n - 1 - i, HASH_SIZE)
            res %= HASH_SIZE
        return res
