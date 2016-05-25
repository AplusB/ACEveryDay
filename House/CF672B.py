'''
题意：
长度为n的字符串，改变最少的字符数量，使得它没有任何重复的子串。求最少改变字符数。
思路：
字符集是小写字母，那么肯定长度超过26必有重复。为了不重复必须是所有字符全不相同。
ps：其实我就是想用一下python的set而已…与C++相比，python中的set其实是hash判重，也就是O(1)的。但是set中的元素是无序的。可以多了解一下set了。
'''
__author__ = "House"

n = int(raw_input())
s = raw_input()
if n > 26:
    print -1
    exit()
f = set()
for i in s:
    f.add(i)
print n - len(f)
