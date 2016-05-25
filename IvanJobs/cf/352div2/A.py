#prepare
c = ''
i = 1
while True:
    c += str(i)
    i += 1
    if len(c) > 1010:
        break
n = int(raw_input())
print c[n - 1]


