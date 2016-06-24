
n, m = map(int, raw_input().split())

d1, d2 = {}, {}
t = []
x = n - 1
t.append(x % 7)
x /= 7
while x != 0:
    t.append(x % 7)
    x /= 7
l1 = len(t)

t = []
x = m - 1
t.append(x % 7)
x /= 7
while x != 0:
    t.append(x % 7)
    x /= 7

l2 = len(t)


for x in xrange(n):
    y = x
    t = []
    t.append(y % 7)
    y /= 7
    while y != 0:
        t.append(y % 7)
        y /= 7
    
    if len(t) >= 7:
        break
    elif l1 - len(t) >= 2:
        continue
    elif l1 - len(t) == 1:
        s = set(t)
        if 0 in s:
            continue
        else:
            s.add(0)
            tup = tuple(s)
            if len(t) == len(tup) - 1:
                if tup in d1:
                    d1[tup] += 1
                else:
                    d1[tup] = 1

    else:
        tup = tuple(set(t))
        if len(t) == len(tup):
            if tup in d1:
                d1[tup] += 1
            else:
                d1[tup] = 1

for x in xrange(m):
    y = x
    t = []
    t.append(y % 7)
    y /= 7
    while y != 0:
        t.append(y % 7)
        y /= 7
    
    if len(t) >= 7:
        break
    elif l2- len(t) >= 2:
        continue
    elif l2 - len(t) == 1:
        s = set(t)
        if 0 in s:
            continue
        else:
            s.add(0)
            tup = tuple(s)
            if len(t) == len(tup) - 1:
                if tup in d2:
                    d2[tup] += 1
                else:
                    d2[tup] = 1

    else:
        tup = tuple(set(t))
        if len(t) == len(tup):
            if tup in d2:
                d2[tup] += 1
            else:
                d2[tup] = 1

res = 0


for k1, v1 in d1.items():
    for k2, v2 in d2.items():
        s = (set(k1) | set(k2))
        if len(s) == len(k1) + len(k2):
            res += v1 * v2

print res

