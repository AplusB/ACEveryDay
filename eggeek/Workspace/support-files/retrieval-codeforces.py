#!/usr/bin/env python
# -*- encoding: utf-8 -*-
import requests

url = 'http://codeforces.com/api/problemset.problems'
rep = requests.get(url)
s = rep.json()

problems = s['result']['problems']
ps = s['result']['problemStatistics']
res = [i for i in problems]
for i in range(len(ps)):
    res[i].update(ps[i])
res = [i for i in res if i['solvedCount'] < 2000]
res.sort(key=lambda x: x['solvedCount'], reverse=True)
format_p = lambda x: "%4d,%s/%s,%s" % (x['solvedCount'], x['contestId'], x['index'], x['name'])
data = [format_p(i) for i in res]
with open("problems", "w") as f:
    for i in data:
        f.write(i.encode('utf-8') + '\n')
        sd
