L = set()
for i in range(10):
    L.add(str(i))
L = L.union(set(['A', 'B', 'C', 'D', 'E']))
s = list(raw_input())
i = 1
size = len(s)
while i < size:
    j = -1
    if s[i - 1] == '0' and s[i] == 'k':
        # ok, start colleting
        tmp = []
        j = i + 1
        # get rid of prefix zeros
        zerocnt = 0
        while j < size and s[j] == '0':
            zerocnt += 1
            j += 1
        while (j < size) and (s[j] in L):
            tmp.append(s[j])
            j += 1
        flag = False
        if len(tmp) != 0:
            if zerocnt == 0:
                print '0k' + ''.join(tmp)
            else:
                print '0k0'
                flag = True
        else:
            if zerocnt >= 1:
                print '0k0'
            if zerocnt > 2:
                flag = True
        if flag:
            i = j
        else:
            i = j + 1
    else:
        i += 1
