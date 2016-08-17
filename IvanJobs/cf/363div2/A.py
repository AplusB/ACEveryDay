n = int(raw_input())
ds = list(raw_input())
cors = map(int, raw_input().split())

res = 10**20
for _t in range(1, n):
# judge cors[_t - 1] & cors[_t]

    if ds[_t - 1] == 'R' and  ds[_t] == 'L':
        res = min(res, abs(cors[_t - 1] - cors[_t])/2) 

if res == 10**20:
    print -1
else:
    print res
