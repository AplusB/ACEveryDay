T = int(raw_input())

for _t in range(T):
    N = int(raw_input())
    A = map(int, raw_input().split())
    B = map(int, raw_input().split())
    
    A2 = [A[0],]
    for i in range(1, N):
        A2.append(A[i] - A[i - 1])

    res = 0
    for i in range(N):
        if B[i] <= A2[i]:
            res += 1
    print res

