n, t = map(int, raw_input().split())

glass = []
for i in range(n):
    glass.append([0] * (i + 1))
cham = 2 ** (n - 1)
j, cur = 0, [cham * t, ]
flag = cham * t
while flag != 0 and j < n:
    size = len(glass[j])
    res = []
    for k in range(size):
        # judge cur[k] ~ glass[j][k]
        pending = []
        if cur[k] + glass[j][k] <= cham:
            pending = [0.0, 0.0]
            glass[j][k] += cur[k]
            flag -= cur[k]
        else:
            delta = cur[k] + glass[j][k] - cham 
            flag -= (cham - glass[j][k])
            pending = [delta/2.0, delta/2.0]
            glass[j][k] = cham 
        if len(res) == 0:
            res.extend(pending)
        else:
            res[len(res) - 1] += pending[0]
            res.append(pending[1])
    cur = res 
    j += 1

# count full
res = 0
for i in range(n):
    tmp =  glass[i]
    res += tmp.count(cham)

print res
