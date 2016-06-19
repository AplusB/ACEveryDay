n = int(raw_input())
a = map(int, raw_input().split())

a.sort()

consider = 1
i = 0

while i < n:
    if a[i] >= consider:
        consider += 1
    else:
        pass
    i += 1

print consider


