#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int f[1005];
int found(int x)
{
        if(f[x]!=x)
        return f[x]=found(f[x]);
        return x;
}
void mix(int x,int y)
{
        int t1,t2;
        t1=found(x);
        t2=found(y);
        if(t1!=t2)
        {
                f[t2]=t1;
        }
}
int main()
{
    int tt=0,T,m,n,x,y;
    scanf("%d",&T);
    while(T--)
    {
            int ans=0;
            scanf("%d %d",&m,&n);
            for(int i=1;i<=m;i++)
                f[i]=i;
            for(int i=0;i<n;i++)
            {
                    scanf("%d %d",&x,&y);
                    mix(x,y);
            }
            for(int i=1;i<=m;i++)
            {
                  if(f[i]==i) ans++;
            }
            printf("%d\n",ans);
    }
    return 0;
}
