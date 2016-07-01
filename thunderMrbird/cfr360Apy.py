n,d= map(int,input().split())
ans=0
sav=0
for i in range(d):
    s=input()
    if s.count('0') == 0:
        ans=max(ans,sav)
        sav=0
    else: sav+=1
ans=max(ans,sav)
print(ans)
