n, x = map(int, raw_input().split())

unhappy = 0
for _t in range(n):
    flag, d = raw_input().split()
    d = int(d)
    if flag == '+':
        x += d
    else:
        if x < d:
            unhappy += 1
        else:
            x -= d

print '%d %d' %(x, unhappy)

