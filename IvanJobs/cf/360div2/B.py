n = int(raw_input())

res = list(str(n))

tmp = list(str(n))
tmp.reverse()

res.extend(tmp)

print ''.join(res)
