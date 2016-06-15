n = int(raw_input())

aup = n/1234567
yes = False
for a in xrange(aup + 1):
    remain = n - a * 1234567

    bup = remain / 123456

    for b in xrange(bup + 1):
        remain2 = remain - b * 123456

        if remain2 % 1234 == 0:
            yes = True
            break
    if yes:
        break

if yes:
    print "YES"
else:
    print "NO"
