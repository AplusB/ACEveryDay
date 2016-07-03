n, d = map(int, raw_input().split())

started, cnt = False, 0
res = 0
for _t in range(d):
    v = int(raw_input(), 2)
    if v == (2**n - 1):
        if started:
            res = max(res, cnt)
            started = False
    else:
        if started == False:
            cnt = 1
            started = True
        else:
            cnt += 1

if started:
    res = max(res, cnt)

print res
