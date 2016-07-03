s = raw_input()

def prefix(p):
    m = len(p)
    if m <= 1:
        return 0

    f = [0] * (m + 1)

    f[0], f[1] = 0, 0

    for i in range(1, m):
        j = f[i]
        while j != 0 and p[i] != p[j]:
            j = f[j]

        if p[i] == p[j]:
            f[i + 1] = j + 1
        else:
            f[i + 1] = 0
    return f
print prefix(list(s))
