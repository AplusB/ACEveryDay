def gcd(a, b):
    if a < b:
        a, b = b, a
    while b != 0:
        c = a % b
        a, b = b, c

    return a

n = int(raw_input())
for _t in range(n):
    num = int(raw_input())
    vs = map(int, raw_input().split())
    
    # C(num, 2)
    res = -1
    for i in range(num):
        for j in range(i + 1, num):
            g = gcd(vs[i], vs[j])
            gcm = vs[i] * vs[j] / g
            if res == -1:
                res = gcm
            else:
                res = min(res, gcm)

    print res
