class Solution:
    """
    @param {int} n an integer.
    @return {int} the nth prime number as description.
    """
    def nthUglyNumber(self, n):
        # write your code here
        pending = [1, 2, 3, 4, 5, 6, 8, 9, 10, 12]
        
        s = len(pending)

        if n > s:
            cnt = n - s + 5
            for _t in range(cnt):
                i, j, res = 0, s - 1, 2**65

                while i < j:
                    mid, maxv = (i + j) /2, pending[s - 1]
                    curr = pending[mid]
                    
                    if curr * 2 > maxv:
                        res = min(res, curr * 2)
                        j = mid - 1
                    else:
                        i = mid + 1


                i, j = 0, s - 1
                while i < j:
                    mid, maxv = (i + j) / 2, pending[s - 1]
                    curr = pending[mid]

                    if curr * 3 > maxv:
                        res = min(res, curr * 3)
                        j = mid - 1
                    else:
                        i = mid + 1


                i, j = 0, s - 1
                while i < j:
                    mid, maxv = (i + j) / 2, pending[s - 1]
                    curr = pending[mid]

                    if curr * 5 > maxv:
                        res = min(res, curr * 5)
                        j = mid - 1
                    else:
                        i = mid + 1



                pending.append(res)
                s += 1
        print pending
        return pending[n - 1]

sol = Solution()
print sol.nthUglyNumber(41)
