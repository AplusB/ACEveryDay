# prepare

# get prime
import math
import pdb


PSET = set()
PLIST = []
CON = [False] * 400010

m = int(math.sqrt(400010.0))

for i in range(2, m + 1):
    if CON[i] == False:
        for j in range(i*i, 400010, i):
            CON[j] = True
# get PLIST, PSET

for i in range(2, 400010):
    if CON[i] == False:
        PLIST.append(i)
        PSET.add(i)

def extract_primes(v):
    m = int(math.sqrt(v * 1.0))
    res = {}
    i = 0
    n = len(PLIST)
    while i < n and i < m and v > 1:
        pr = PLIST[i]
        
        if v % pr == 0:
            exp = 0
            while v % pr == 0:
                exp += 1 
                v /= pr

            res[pr] = exp
            
        i += 1
    res[1] = 1
    return res

T = int(raw_input())

for _t in range(T):
    n, m = map(int, raw_input().split())
    if n == 2 and m == 2:
        print 6
        continue
    if n == 2 and m != 2:
        print (n + m + m * (m - 1)) % 2 ** 30
        continue
    if n != 2 and m == 2:
        print (n + m + n * (n - 1)) % 2 ** 30
        continue
    # 
    maxv = max(n - 1, m - 1)
    dextract = {}
    dextract[1] = {1:1}
    for i in range(2, maxv + 1):
        dextract[i] = extract_primes(i)


    pairs = []
    for i in range(1, n):
        for j in range(1, m):
            pairs.append([i, j])

    #pdb.set_trace()

    upairs = set()
    for pair in pairs:
        p0, p1 = pair[0], pair[1]
        d0, d1 = dextract[p0], dextract[p1]

        s0 = set(d0.keys())
        s1 = set(d1.keys())

        s3 = s0 & s1
        print s3
        if len(s3) != 0:
            for pr in s3:
                minexp = min(d0[pr], d1[pr])
                p0 /= (pr ** minexp)
                p1 /= (pr ** minexp)
                d0[pr] -= minexp
                d1[pr] -= minexp

        p0 = int(p0)
        p1 = int(p1)
        item = (p0, p1)
        if p0 > 0 and p1 > 0:
            upairs.add(item)
    print upairs

    # here, we got upairs
    ans = n + m + 2
    part = 0
    for pair in upairs:
        part += min((n - 1) / pair[0], (m - 1) / pair[1]) * 4

    ans += part
    ans %= 2**30

    print ans
