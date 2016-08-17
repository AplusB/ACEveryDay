import math

a, b = map(int, raw_input().split())
n = int(raw_input())
res = -1
for _t in range(n):
    x, y, sp = map(int, raw_input().split())

    tmp = math.sqrt((x - a)**2 + (y - b)**2 + 0.0)/sp

    if res == -1:
        res = tmp
    else:
        res = min(res, tmp)

print res
