n=int(input())
a=input()
a=a.split()
for i in range(n):
	a[i]=int(a[i])
for j in range (n-1):
	for i in range (n-j-1):
		if a[i]>a[i+1]:
			t=a[i]
			a[i]=a[i+1]
			a[i+1]=t
			print(i+1, i+2)
