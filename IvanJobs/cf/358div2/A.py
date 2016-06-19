import pdb
n, m = map(int, raw_input().split())

n_map, m_map = {}, {}

for i in range(1, 10):
    tmp = n - (i - 1)
    if tmp < 0:
        n_map[i] = 0
    else:
        n_map[i] = tmp / 10
        if tmp % 10 >= 1:
            n_map[i] += 1

    tmp = m - (i - 1)
    if tmp < 0:
        m_map[i] = 0
    else:
        m_map[i] = tmp / 10
        if tmp % 10 >= 1:
            m_map[i] += 1


n_map[0] = n/10
m_map[0] = m/10

#pdb.set_trace()

res = 0
res += n_map[0] * m_map[5]
res += n_map[1] * m_map[4]
res += n_map[2] * m_map[3]
res += n_map[3] * m_map[2]
res += n_map[4] * m_map[1]
res += n_map[5] * m_map[0]
res += n_map[6] * m_map[9]
res += n_map[7] * m_map[8]
res += n_map[8] * m_map[7]
res += n_map[9] * m_map[6]

res += n_map[0] * m_map[0]

for i in range(1, 10):
    res += n_map[i] * m_map[10 - i]

print res
