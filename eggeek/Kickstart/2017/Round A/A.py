def f1(n):
    return n * (n + 1) / 2

def f2(n):
    return n * (n + 1) * (2*n + 1) / 6

def f3(n):
    return (n * (n + 1)) ** 2 / 4


def solve():
    R, C = map(int, raw_input().split())
    mod = int(1e9) + 7
    ub = min(R-1, C-1)
    res = R * C * f1(ub) + f3(ub) - (R + C) * f2(ub)
    res %= mod
    return res


def main():
    cas = input()
    for i in range(1, cas+1):
        ans = solve()
        print "Case #%d: %d" % (i, ans)

if __name__ == "__main__":
    main()
