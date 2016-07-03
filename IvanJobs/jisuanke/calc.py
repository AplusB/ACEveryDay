import pdb

raw = raw_input()
positive = True
if raw[0] == '-':
    positive = False
    raw = raw[1:]

intpart, exp = raw.split('e')

exp = int(exp)

idx = intpart.find('.')

part0, part1, part2 = 0, 'e', 0
#pdb.set_trace()

if idx == -1:
    intpart = int(intpart)
    intpart = str(intpart)
    n = len(intpart)

    if n == 1:
        part0 = intpart
        part2 = exp
    else:
        part0 = intpart[0:1]
        part0 += '.'
        part0 += intpart[1:]

        part2 = exp + (n - 1)
else:
    n = len(intpart)
    p0 = int(intpart[0:idx])
    if p0 == 0:
        # from idx + 1 -> ~ 
        j = idx + 1
        while j < len(intpart) and intpart[j] == '0':
            j += 1

        k = n - 1
        while intpart[k] == '0':
            k -= 1
        if len(intpart[j + 1: k + 1]) != 0:
            part0 = intpart[j] + '.' + intpart[j + 1: k + 1]
        else:
            part0 = intpart[j]

        part2 = exp - (j - idx)
    else:
        if p0 < 10:
            k = n - 1
            while intpart[k] == '0':
                k -= 1
            if len(intpart[idx + 1: k + 1]) != 0:
                part0 = str(p0) + '.' + intpart[idx + 1: k + 1]
            else:
                part0 = str(p0)
            part2 = exp
        else:
            p0 = str(p0)
            k = n - 1
            while intpart[k] == '0':
                k -= 1
            if len(p0[1:] + intpart[idx + 1: k + 1]) != 0:
                part0 = p0[0] + '.' + p0[1:] + intpart[idx + 1: k + 1]
            else:
                part0 = p0[0]
            part2 = exp + (len(p0) - 1)

if positive:
    print '%s%s%d' % (part0, part1, part2)
else:
    print '-%s%s%d' % (part0, part1, part2)


