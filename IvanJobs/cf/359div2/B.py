n = int(raw_input())
A = map(int, raw_input().split())

def ok(a):
    n = len(a)
    for i in range(n - 1):
        if a[i + 1] >= a[i]:
            pass
        else:
            return False
    return True

while ok(A) == False:
    for i in range(n - 1):
        p = i
        while p + 1 < n:
            if A[p] > A[p + 1]:
                A[p + 1], A[p] = A[p], A[p + 1]
            else:
                break
            p += 2

        if p == i:
            pass
        else:
            print '%d %d' %(i + 1, p - 1 + 1)


