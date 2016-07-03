
sym = []
for i in range(26):
    sym.append(chr(ord('a') + i))

def prefix_l(p):
    m = len(p)
    if m <= 1:
        return 0
    f = [0] * (m + 1)

    f[0], f[1] = 0, 0

    for i in range(1, m):
        j = f[i]
        while j != 0 and p[i] != p[j]:
            j = f[j]

        if p[i] == p[j]:
            f[i + 1] = j + 1
        else:
            f[i + 1] = 0
    return f[m - 1] 
T = int(raw_input())
for _t in range(T):
    cnts = map(int, raw_input().split())
    s0 = []
    for i in range(26):
        if cnts[i] > 0:
            s0.extend([sym[i],] * cnts[i])

    # make str
    s = []
    flag = True 
    while sum(cnts) != 0:
        if flag:
            for i in range(26):
                if cnts[i] > 0:
                    s.append(sym[i])
                    cnts[i] -= 1
        else:
            for i in range(25, -1, -1):
                if cnts[i] > 0:
                    s.append(sym[i])
                    cnts[i] -= 1
        if flag:
            flag = False
        else:
            flag = True

    pi = []
    ls = len(s)
    for i in range(1, ls):
        # check s[0:i]
        pi.append(prefix_l(s[0:i + 1]))
    v1 = sum(pi)

    pi = []
    ls = len(s0)
    for i in range(1, ls):
        print s[0:i + 1]
        print prefix_l(s[0:i + 1])
        pi.append(prefix_l(s[0:i + 1]))
    print s0
    print pi
    v0 = sum(pi)
    print min(v0, v1)
