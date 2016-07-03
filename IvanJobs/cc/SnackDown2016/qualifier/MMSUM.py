import pdb

T = int(raw_input())
for _t in range(T):
    n = int(raw_input())
    A = map(int, raw_input().split())

    dp, dp_rev, con = [0] * n, [0] * n, [False] * n

    # make dp
    dp[0] = A[0]
    for i in range(1, n):
        if A[i] <= A[i] + dp[i - 1]:
            con[i] = True 
        dp[i] = max(A[i], A[i] + dp[i - 1])

    # make dp_rev
    dp_rev[n - 1] = A[n - 1]
    for i in range(n - 2, -1, -1):
        dp_rev[i] = max(A[i], A[i] + dp_rev[i + 1])

    # find max
    maxv = max(dp)
    
    segs = []
    # collect max segs
    for i in range(n):
        if dp[i] == maxv:
            # find it
            e = i
            j = i
            while j >= 0 and con[j]:
                j -= 1
            b = j
            segs.append([b, e])

    #pdb.set_trace()
    # handle seg
    res = maxv
    for seg in segs:
        delta = 0
        b, e = seg[0], seg[1]
        # delta from internal
        tmp = []
        for j in range(b, e + 1):
            tmp.append(A[j])
        minv = min(tmp)
        if minv < 0:
            delta = max(delta, abs(minv))
        # delta from left

        # delta from right


        v = maxv + delta
        res = max(res, v)

    print res
