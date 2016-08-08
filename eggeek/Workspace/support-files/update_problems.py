#!/usr/bin/env python
# -*- encoding: utf-8 -*-
from os import listdir as ls
from os.path import isfile
from os import path
import requests


def load():
    p = '../../codeforces/'
    solved = [i.split('.')[0] for i in ls(p) if isfile(path.join(p, i))]
    return solved


def work():
    solved = load()

    print 'requesting...'
    url = 'http://codeforces.com/api/problemset.problems'
    rep = requests.get(url)
    s = rep.json()

    if rep.status_code == 200 and s['status'] == 'OK':
        print 'success, updating...'
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
                if i.split(',')[1].replace('/', '') not in solved:
                    f.write(i.encode('utf-8') + '\n')
        print 'done!'
    else:
        print 'failed'


if __name__ == "__main__":
    work()
