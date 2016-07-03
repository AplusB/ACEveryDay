n = int(raw_input())
a = map(int, raw_input().split())

idx1 = a.index(1)
idxn = a.index(n)

res = []
res.append(abs(0 - idx1))
res.append(abs(n - 1 - idx1))
res.append(abs(0 - idxn))
res.append(abs(n - 1 - idxn))

print max(res)

