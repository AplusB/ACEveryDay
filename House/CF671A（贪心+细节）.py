'''
题意：
二维平面有n个瓶子1个垃圾桶和A、B两个人，这两个人捡瓶子扔进垃圾桶再去捡其他的瓶子，直到所有瓶子都扔完。问A和B最小路程之和。
思路：
对于A和B去捡的第一个瓶子距离贡献为dis(a or b->x)+dis(x->t)，对于其他的瓶子贡献均为dis(x->t)*2。
那么只需要找“以哪个瓶子当第一个瓶子节省距离最多就好了”。
这时需要注意“节省距离最多”对于A和B来说可能是同一个瓶子，那么我们在维护A和B的最优的同时还要维护次优。
注意细节：1、如果A、B中有一个人距离所有瓶子很远，那么他不应该参加捡瓶子。2、只有一个瓶子的特殊情况。
ps：
题目本来就不难…我只是想练习python写代码hhh！
值得思考的点：1、input如何能写的优雅点。2、一开始我用了sort结果TLE了，应该研究一下sort的效率和自定义cmp的技巧。
'''

__author__ = "House"

import math


def dis(fx1, fy1, fx2, fy2):
    dertx = fx2 - fx1
    derty = fy2 - fy1
    return math.sqrt(dertx * dertx + derty * derty)


if __name__ == "__main__":
    tmp = raw_input().split(" ")
    ax, ay, bx, by, tx, ty = int(tmp[0]), int(tmp[1]), int(tmp[2]), int(tmp[3]), int(tmp[4]), int(tmp[5])
    n = int(raw_input())
    lis = []
    all = 0
    if n == 1:
        line = raw_input()
        col = line.split(" ")
        x = int(col[0])
        y = int(col[1])
        print min(dis(ax, ay, x, y) + dis(x, y, tx, ty), dis(bx, by, x, y) + dis(x, y, tx, ty))
        exit(0)
    for i in xrange(n):
        line = raw_input()
        col = line.split(" ")
        x = int(col[0])
        y = int(col[1])
        da = dis(ax, ay, x, y)
        db = dis(bx, by, x, y)
        dt = dis(tx, ty, x, y)
        lis.append((i, da - dt, db - dt, dt * 2))
        all += dt * 2
    bestb1, bestb2 = besta1, besta2 = lis[0][0], lis[1][0]
    if lis[besta2][1] < lis[besta1][1]:
        besta1, besta2 = besta2, besta1
    if lis[bestb2][2] < lis[bestb1][2]:
        bestb1, bestb2 = bestb2, bestb1
    for i in xrange(2, n):
        if lis[besta2][1] > lis[i][1]:
            besta2 = i
            if lis[besta2][1] < lis[besta1][1]:
                besta1, besta2 = besta2, besta1
        if lis[bestb2][2] > lis[i][2]:
            bestb2 = i
            if lis[bestb2][2] < lis[bestb1][2]:
                bestb1, bestb2 = bestb2, bestb1
    ans = min(all + lis[besta1][1], all + lis[bestb1][2])
    #print besta1, besta2, bestb1, bestb2
    if besta1 == bestb1:
        print min(ans, all + lis[besta1][1] + lis[bestb2][2],
                  all + lis[bestb1][2] + lis[besta2][1])
    else:
        print min(ans, all + lis[besta1][1] + lis[bestb1][2])
