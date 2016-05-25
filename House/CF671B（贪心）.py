'''
题意：
n堆硬币每堆为f[i]个，做至多k次操作，每次从最多的堆里面拿一个放到最少的堆里。问最终最多的堆比最少的堆多多少
思路：
尽量多的操作，因为操作永远不会使结果变坏。
可以把拿硬币和放硬币分开考虑，O(n)扫描f，看k次操作之后min堆里最多有多少，同理得出max堆里最少有多少。
（ps：这里记得优化一下，不要扫描f两次，python很卡时间）
如果max>min，则结果为max-min，否则判断sum(f)是否能平分n份。
（ps：这里是max>min，而不是>=，因为如果==且sum(f)不能平分，这时min部分可能包含min+1，而且min+1>max，比如f=[1,2,7],k=4）
ps：input还是可以写的好看一点的…这次比上次好多了 =。=
'''

__author__ = "House"

if __name__ == "__main__":
    n, k = [int(i) for i in raw_input().split()]
    f = [int(i) for i in raw_input().split()]
    f.sort()
    min, tmp = int(1e10), k
    i = 0
    while i < n - 1:
        cnt = i + 1
        sub = f[i + 1] - f[i]
        if cnt * sub <= tmp:
            tmp -= cnt * sub
        else:
            min = tmp / cnt + f[i]
            break
        i += 1
    if i == n - 1:
        if sum(f) % n == 0:
            ans = 0
        else:
            ans = 1
        print ans
        exit()
    max, tmp = -1, k
    j = n - 1
    while j > i:
        cnt = n - j
        add = f[j] - f[j - 1]
        if cnt * add <= tmp:
            tmp -= cnt * add
        else:
            max = f[j] - tmp / cnt
            break
        j -= 1
    if max > min:
        ans = max - min
    else:
        if sum(f) % n == 0:
            ans = 0
        else:
            ans = 1
    print ans
