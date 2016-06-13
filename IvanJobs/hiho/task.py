N = int(raw_input())

BS, ES, M = [], [], set()
for i in range(N):

    tmp = map(int, raw_input().split())

    BS.append(tmp[0])
    ES.append(tmp[1])
    M.add(tmp[0])
    M.add(tmp[1])

BS.sort()
ES.sort()

lb = len(BS)
le = len(ES)

res = -1
cur = 0
bi, ei = 0, 0
for line in M:
    while bi < lb and BS[bi] == line:
        cur += 1 
        bi += 1
    while ei < le and ES[ei] == line:
        cur -= 1
        ei += 1
    res = max(res, cur)

print res
