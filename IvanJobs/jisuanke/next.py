p = raw_input()

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

print prefix


