#!/usr/bin/env python
# -*- encoding: utf-8 -*-
import json
from collections import defaultdict
from tinydb import TinyDB, Query

config = json.load(open("config.json", "r"))


def get_current_problem_set():
    import requests
    url = config['api_problems']
    print "requesting..."
    resp = requests.get(url)
    if resp.status_code != 200:
        print "request failed"
        return
    print "request success"
    respj = resp.json()['result']
    return respj


def get_problem_set_from_json():
    import json
    respj = {}
    with open("r.json", "r") as f:
        respj = json.load(f)
    return respj['result']


def format_info():
    resp = get_current_problem_set()
    solved = get_solved()
    problems = resp['problems']
    statistic = resp['problemStatistics']
    info = defaultdict(lambda: {'isSolved': False})
    for p in problems:
        eid = (p['contestId'], p['index'])
        info[eid].update(p)
    for s in statistic:
        eid = (s['contestId'], s['index'])
        info[eid].update(s)
    for s in solved:
        eid = (int(s.split('/')[0]), s.split('/')[1])
        info[eid].update({'isSolved': True})
    return info


def batch_update(info):
    db = TinyDB('db.json')
    rows = {(i['contestId'], i['index']): i for i in db.all()}
    insert = {}
    update = {}
    print "Calculating insert row & update row"
    for k, v in info.items():
        if rows.get(k, None) is None:
            insert[k] = v
        elif rows[k]['isSolved'] != v['isSolved']:
            update[k] = {'isSolved': v['isSolved'], 'name': v['name']}
    print "Calculation finish, %d rows going to be inserted, %d rows going to be updated" % \
        (len(insert.keys()), len(update.keys()))
    raw_input("Press any key to continue.")
    problem = Query()
    for v in insert.values():
        print "insert row: %d, %s, %s" % (v['contestId'], v['index'], v['name'])
        db.insert(v)
    for k, v in update.items():
        print "update row: %d, %s, %s, solved: %r" % (k[0], k[1], v['name'], v['isSolved'])
        db.update(v, (problem.contestId == k[0]) & (problem.index == k[1]))
    print 'Done!'


def get_solved():
    from os import listdir as ls
    from os.path import isfile
    from os import path
    import re
    p = config['directory']
    solved = [i.split('.')[0] for i in ls(p) if isfile(path.join(p, i))]
    solved = [re.sub("^\d+", re.findall("^\d+", i)[0] + '/', i) for i in solved]
    return solved


def work():
    info = format_info()
    batch_update(info)

if __name__ == "__main__":
    work()
