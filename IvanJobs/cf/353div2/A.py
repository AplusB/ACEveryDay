a, b, c = map(int, raw_input().split())

delta = b - a

if delta * c < 0:
    print 'NO'
else:
    if delta * c == 0:
        if delta == 0:
            print 'YES'
        else:
            print 'NO'
    else:
        if abs(delta) % abs(c) == 0:
            print 'YES'
        else:
            print 'NO'
