n, a, b, c, d = map(int, raw_input().split())

little = [1, 1 + c - b, 1 - a + d - b + c, 1 + d - a]
big = [n, n + c - b, n - a + d - b + c, n + d - a ]

maxlittle = max(little)
minbig = min(big)

if maxlittle > minbig:
    print 0
else:
    print (minbig - maxlittle + 1) * n
