n = int(raw_input())

yes = False
for i in range(n):
    handle, v1, v2 = raw_input().split()

    v1 = int(v1)
    v2 = int(v2)

    if (v2 > v1) and (v1 >= 2400):
        yes = True
if yes:
    print "YES"
else:
    print "NO"
