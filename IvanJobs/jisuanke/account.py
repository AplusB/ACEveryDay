import pdb

buf = {}

def P(p):
    if p in buf:
        return buf[p]

    leng = len(p)
    prefix = [0] * leng

    for i in range(1, leng):
        k = prefix[i - 1]
        while p[i] != p[k] and k != 0:
            k = prefix[k - 1]
        if p[i] == p[k]:
            prefix[i] = k + 1
        else:
            prefix[i] = 0

    lv = prefix[leng - 1]
    gran = leng - lv
    v = 0
    if leng % gran == 0:
        v = (leng / gran) - 1

    buf[p] = v
    return v

S = raw_input()

L = len(S)

ans = 0

vis = set()

for sep in range(0, L - 1):
#    pdb.set_trace()

    s0, s1, idex0, idex1 = [], [], [], []
    # [0, sep], [sep + 1, L - 1]
    for i in range(0, sep + 1):
        for j in range(i, sep + 1):
            s0.append(S[i : j + 1])
            idex0.append([i, j + 1])
    for i in range(sep + 1, L):
        for j in range(i, L):
            s1.append(S[i : j + 1])
            idex1.append([i, j + 1])


    for i in range(len(s0)):
        for j in range(len(s1)):
            str0, str1 = s0[i], s1[j]
            key = ':'.join(map(str,idex0[i])) + ':' + ':'.join(map(str, idex1[j]))
            if key in vis:
                pass
            else:
                if P(str0) == P(str1):
                    ans += 1
                vis.add(key)
#pdb.set_trace()


print ans 
