#!/usr/bin/env python
with open('B-large-practice.in', 'r') as fin, open('B-large-practice.out', 'w') as fout:
    T = int(fin.readline())
    for _t in range(1, T + 1):
        n = int(fin.readline())
        d = {}
        for i in range(2*n - 1):
            tmp = map(int, fin.readline().strip().split())
            for item in tmp:
                if item in d:
                    d[item] += 1
                else:
                    d[item] = 1
        res = []
        for k in d:
            if d[k] & 1:
                res.append(k)
        res.sort()
        fout.write('Case #%d: %s\n' % (_t, ' '.join(map(str,res))))
