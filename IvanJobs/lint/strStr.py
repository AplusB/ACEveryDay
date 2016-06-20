class Solution:
    def next(self, s):
        n = len(s)
        res = [0] * (n + 1)
        
        for i in range(1, n):
            j = res[i]
            while j != 0 and s[j] != s[i]:
                j = res[j]
            if s[i] == s[j]:
                res[i + 1] = res[j] + 1
            else:
                res[i + 1] = 0
        return res
        
    def strStr(self, source, target):
        if target == '' :
            return 0
        if target == None:
            return -1
        if source == '' or source == None:
            return -1
        f = self.next(target)
        # write your code here
        n, m = len(source), len(target)
        
        j = 0
        for i in range(n):
            while j > 0 and source[i] != target[j]:
                j = f[j]
            if source[i] == target[j]:
                j += 1
            if j == m:
                return i - m + 1
        return -1
            
            
