n = int(raw_input())

mindayoff, maxdayoff = n / 7 * 2, n / 7 * 2

remain = n % 7

if remain > 2:
    maxdayoff += 2
else:
    maxdayoff += remain 

if remain > 5:
    mindayoff += remain - 5

print '%d %d' % (mindayoff, maxdayoff)
