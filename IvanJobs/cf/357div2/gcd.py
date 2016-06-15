#!/usr/bin/env python

import sys

v1 = int(sys.argv[1])
v2 = int(sys.argv[2])


def gcd(a, b):
    if a == 0:
        return b

    while b != 0:
        if a > b:
            a -= b
        else:
            b -= a
    return a


print gcd(v1, v2)
