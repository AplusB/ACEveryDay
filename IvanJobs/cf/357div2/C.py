import heapq

n = int(raw_input())

res = []
heap = []
heapq.heapify(heap)

for _t in range(n):
    line = raw_input()

    if line[0] == 'r': # removeMin
        if len(heap) == 0:
            res.append('insert 0')
            heapq.heappush(heap, 0)
        res.append(line)
        heapq.heappop(heap)

    if line[0] == 'i': # insert x
        op, x = line.split()
        x = int(x)
        res.append(line)
        heapq.heappush(heap, x)

    if line[0] == 'g': # getMin x
        op, x = line.split()
        x = int(x)

        if len(heap) == 0:
            heapq.heappush(heap, x)
            res.append("insert %d" % (x, ))
        else:
            while (len(heap) != 0) and (heap[0] < x):
                heapq.heappop(heap)
                res.append("removeMin")
            if len(heap) == 0:
                heapq.heappush(heap, x)
                res.append("insert %d" % (x, ))
            else:
                if heap[0] == x:
                    pass
                else:
                    heapq.heappush(heap, x)
                    res.append("insert %d" % (x, ))
        res.append(line)


print len(res)
for line in res:
    print line

