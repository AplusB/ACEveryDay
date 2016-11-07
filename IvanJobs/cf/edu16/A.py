line = raw_input().strip()

c = ord(line[0]) - ord('a') + 1
r = 9 - int(line[1])

if r > 1 and r < 8 and c > 1 and c < 8:
    print 8
elif (r > 1 and r < 8 and (c == 1 or c == 8)) or (c > 1 and c < 8 and (r == 1 or r == 8)):
    print 5
else:
    print 3
