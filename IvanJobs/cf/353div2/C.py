n = int(raw_input())
a = map(int, raw_input().split())
d = {}
prefix_sum = [0] * n
prefix_sum[0] = a[0]
for i in range(1, n):
    prefix_sum[i] = a[i] + prefix_sum[i - 1]
# dict prefix_sum
for i in prefix_sum:
    if i in d:
        d[i] += 1
    else:
        d[i] = 1
print n - max(d.values())


