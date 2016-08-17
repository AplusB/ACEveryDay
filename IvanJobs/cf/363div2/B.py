n, m = map(int, raw_input().split())

pot = []
for _t in range(n):
    pot.append(list(raw_input()))

wcnt = 0
pending = []

for i in range(n):
    for j in range(m):
        if pot[i][j] == '*':
            wcnt += 1
            pending.append((i, j))

resr, resc = -1, -1
good = False
for r, c in pending:
    cnt = 0
    for _c in range(m):
        if pot[r][_c] == '*':
            cnt += 1
    for _r in range(n):
        if pot[_r][c] == '*':
            cnt += 1
    if pot[r][c] == '*':
        cnt -= 1
    if cnt == wcnt:
        good = True
        resr = r
        resc = c
        break
if wcnt == 0:
    print 'YES'
    print '1 1'
elif good:
    print 'YES'
    print '%d %d' % (resr + 1, resc + 1)
else:
    print 'NO'
