'''
一道栏题，python代码慢得要死，python2还过不了，必须python3，nlognlogn过不了，n2能过…
'''
__author__ = "House"

import bisect

if __name__ == "__main__":
    n = int(raw_input())
    s = [int(i) for i in raw_input().split()]
    f = [[s[0], 0]]
    outp = list()
    for i in xrange(1, n):
        now = [s[i], i]
        idx = bisect.bisect_left(f, now)
        ans = 0
        if idx == 0:
            ans = f[0][0]
        elif idx == i:
            ans = f[idx - 1][0]
        else:
            if f[idx][1] < f[idx - 1][1]:
                ans = f[idx - 1][0]
            else:
                ans = f[idx][0]
        f[idx:idx] = [now]
        outp.append(str(ans))
    print " ".join(outp)
