n=int(input())
for i in range(n):
  a,b,c=input().split()
  if int(b)>2399 and int(c)>int(b): print("YES"); break
else: print("NO")
