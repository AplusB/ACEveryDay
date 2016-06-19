import pdb

n, m, k = map(int, raw_input().split())
s = raw_input()
t = raw_input()
s = '*' + s
t = '#' + t

cnt = [[0 for m1 in xrange(m + 1)] for n1 in xrange(n + 1)]


for r in xrange(1, n + 1):
    for c in xrange(1, m + 1):
        if s[r] == t[c]:
            cnt[r][c] = 1 + cnt[r - 1][c - 1]

#pdb.set_trace()


dp = [[[0 for i1 in xrange(k + 1)] for j1 in xrange(m + 1)] for p1 in xrange(n + 1)]

for i in xrange(1, n + 1):
    for j in xrange(1, m + 1):
        for p in xrange(1, k + 1):
            if min(i, j) < p:
                break
            if s[i] == t[j]:
                ct = cnt[i][j];
                dp[i][j][p] = dp[i - ct][j - ct][p - 1] + ct
                dp[i][j][p] = max(dp[i][j][p], dp[i - 1][j][p])
                dp[i][j][p] = max(dp[i][j][p], dp[i][j - 1][p])
            else:
                dp[i][j][p] = max(dp[i][j - 1][p], dp[i - 1][j][p])

#pdb.set_trace()


print dp[n][m][k]


