def iswis(a):
	return a % 400 == 0 or (a%100!= 0 and a %4==0)

n = int(input())
wis = iswis(n)
fr = 0;
n += 1
if (wis):
	fr += 1
fr += 1
while (iswis(n) != wis or fr != 0):
	if (iswis(n)):
		fr += 1
	fr += 1
	fr %= 7
	n += 1
print(n)
