'''
题意：
长度为n的环，环上每个点有一个钱数且总和为0（有些地方欠钱），一次操作可以从一个点把一些钱移到相邻的点。问最少多少次操作使得所有点都是0。
思路：
假设一段长度为x的子串和为0，那么x-1次操作肯定能使得这个子串全为零。
那么ans = sigma(xi-1) (i=1...y) = sigma(xi)-y = n-y，也就是说，只要分子串数量尽量多就好了。
子串的性质只有“和为0”，因此我们只需要求前缀和，前缀和相同的两个位置一定可以截成一个子串。
ps：
dict的使用有了新理解，判断x在不在dict中，直接x in dict，而不是x in dict.keys()，因为后者会变成在list中查找元素。
'''
__author__ = "House"

n = int(raw_input())
f = [int(i) for i in raw_input().split()]
d = dict()
add = 0
for i in f:
    add += i
    if add not in d:
        d[add] = 1
    else:
        d[add] += 1
print n - max(d.values())
